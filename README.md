# Selector de destino para navegación 2D

Paquete ROS para suscribirse a distintos tópicos de tipo booleano, para luego publicar un destino en específico para la navegación de un robot. 

Pensado para configurar botones de la aplicación de [ROS Mobile](https://github.com/ROS-Mobile/ROS-Mobile-Android).


# Requisitos 

* ROS
* C++
* Catkin Tools

# Utilización


1. Ajustar parámetros de destino utilizando archivos _yaml_ (Ej: carpeta `param`).


2. Crear lanzador usando como ejemplo `select_ubication_multiple.launch`. 


3. Compilar el paquete utilizando Catkin Tools:

```
catkin build interface_data_navigation
```

4. Ejecutar lanzador:

```
roslaunch interface_data_navigation select_ubication_multiple.launch
```

El paquete está configurado para suscribirse a 8 tópicos a la vez, como se observa en el siguiente ejemplo:

<img src="images/rqt selector.jpg" width="500">

> [!NOTE]
> El tipo del tópico de publicación es `geometry_msgs/PoseStamped`.

Fue utilizado para configurar los botones de la interfaz desarrollada en ROS-Mobile, para especificar un destino distinto a cada botón. 

Ejemplo de la interfaz utilizada:

<img src ="images/rosmobile int.png" height="450">





