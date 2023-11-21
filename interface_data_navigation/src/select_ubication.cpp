#include <interface_data_navigation/select_ubication.h>

SelectUbication::SelectUbication(ros::NodeHandle *_nh, std::string sub_topic, std::string pub_topic){
    // Crear publicador y subscriptor
    sub_bool = _nh->subscribe(sub_topic,1000,&SelectUbication::EstadoBoton, this);
    pub_goal = _nh->advertise<geometry_msgs::PoseStamped>(pub_topic, 1000);

    ubicacion_definida = false;
}
SelectUbication::~SelectUbication(){
}

void SelectUbication::DefineUbication(float x, float y, float z, float w){
    // Ajustar destino
    msg.pose.position.x = x;
    msg.pose.position.y = y;
    msg.pose.position.z = 0;
    msg.pose.orientation.x = 0;
    msg.pose.orientation.y = 0;
    msg.pose.orientation.z = z;
    msg.pose.orientation.w = w;

    msg.header.frame_id = "map";
    ubicacion_definida = true;
}

void SelectUbication::EstadoBoton(const std_msgs::Bool &msg){
    if (ubicacion_definida && msg.data){
        PublicarMensaje();
    }
}

void SelectUbication::PublicarMensaje(){
    msg.header.stamp = ros::Time::now();
    ROS_INFO("Destino seleccionado (%.2f, %.2f)",msg.pose.position.x,msg.pose.position.y);
    pub_goal.publish(msg);
}


