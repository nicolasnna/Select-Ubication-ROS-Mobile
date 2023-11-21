#ifndef INTERFACE_DATA_NAVIGATION_SELECT_UBICATION_H_
#define INTERFACE_DATA_NAVIGATION_SELECT_UBICATION_H_

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Bool.h>
#include <ros/console.h>

class SelectUbication{
    private:
        // Subs Pub
        ros::Subscriber sub_bool;
        ros::Publisher pub_goal;
        // Callback
        void EstadoBoton(const std_msgs::Bool &);
        // Comprobante de ubicacion definidas
        bool ubicacion_definida;

    public:
        // Constructor y destructor
        SelectUbication(ros::NodeHandle *nh, std::string subs_topic, std::string pub_topic);
        ~SelectUbication();
        // Definir ubicacion
        void DefineUbication(float x, float y, float z, float w);
        // Publicar 
        void PublicarMensaje();
        // Mensaje
        geometry_msgs::PoseStamped msg;


};

#endif