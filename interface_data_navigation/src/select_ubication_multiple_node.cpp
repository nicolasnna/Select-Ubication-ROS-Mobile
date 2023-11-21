#include "select_ubication.cpp"

// Datos de ubicacion
float pos_x[8], pos_y[8], rot_z[8], rot_w[8];
// Tópicos
std::string sub_boton[8], pub_goal;
// Función para obtener datos de RosParam
void ObtenerParametros(ros::NodeHandle *_nh);

int main(int argc, char **argv){
    // Iniciar Nodo
    ros::init(argc,argv, "select_ubication");
    ros::NodeHandle nh;
    ObtenerParametros(&nh);
    // Creacion de objetos
    SelectUbication ubicacion1(&nh,sub_boton[0],pub_goal);
    SelectUbication ubicacion2(&nh,sub_boton[1],pub_goal);
    SelectUbication ubicacion3(&nh,sub_boton[2],pub_goal);
    SelectUbication ubicacion4(&nh,sub_boton[3],pub_goal);
    SelectUbication ubicacion5(&nh,sub_boton[4],pub_goal);
    SelectUbication ubicacion6(&nh,sub_boton[5],pub_goal);
    SelectUbication ubicacion7(&nh,sub_boton[6],pub_goal);
    SelectUbication ubicacion8(&nh,sub_boton[7],pub_goal);
    // Definición de ubicaciones
    ubicacion1.DefineUbication(pos_x[0],pos_y[0],rot_z[0],rot_w[0]);
    ubicacion2.DefineUbication(pos_x[1],pos_y[1],rot_z[1],rot_w[1]);
    ubicacion3.DefineUbication(pos_x[2],pos_y[2],rot_z[2],rot_w[2]);
    ubicacion4.DefineUbication(pos_x[3],pos_y[3],rot_z[3],rot_w[3]);
    ubicacion5.DefineUbication(pos_x[4],pos_y[4],rot_z[4],rot_w[4]);
    ubicacion6.DefineUbication(pos_x[5],pos_y[5],rot_z[5],rot_w[5]);
    ubicacion7.DefineUbication(pos_x[6],pos_y[6],rot_z[6],rot_w[6]);
    ubicacion8.DefineUbication(pos_x[7],pos_y[7],rot_z[7],rot_w[7]);

    ros::Rate freq(15);

    while(ros::ok()){
        ros::spinOnce();
        freq.sleep();
    }
}

void ObtenerParametros(ros::NodeHandle *_nh){
    for(int i = 0; i <= 7; i++){
        _nh->getParam("pos_x" + std::to_string(i+1),pos_x[i]);
        _nh->getParam("pos_y" + std::to_string(i+1),pos_y[i]);
        _nh->getParam("rot_z" + std::to_string(i+1),rot_z[i]);
        _nh->getParam("rot_w" + std::to_string(i+1),rot_w[i]);

        _nh->getParam("topico_boton" + std::to_string(i+1),sub_boton[i]);
    }
    _nh->getParam("topico_goal",pub_goal);
}