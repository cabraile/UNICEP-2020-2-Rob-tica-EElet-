#include "ros/ros.h" // Incluir o core do ROS
#include "geometry_msgs/Twist.h" // Permite o uso do Twist
#include <stdlib.h>

int main(int ac, char * av[]) {
	ros::init(ac, av, "aula1_node"); // Falar pro ROS que esse vai ser um no
	ros::NodeHandle n; // Faz interface com o ROS para acessar e mandar informacao

	ros::Publisher cmd_pub = n.advertise< geometry_msgs::Twist  >("/cmd_vel_mux/input/teleop", 10 );
	
	srand(time(NULL));
	ros::Rate loop_rate(10);
	while( ros::ok() ) {

		// Criar mensagem e popular
		geometry_msgs::Twist cmd_msg;
		cmd_msg.linear.x = 0.5;
		cmd_msg.angular.z = 0.5 * ( 2 * (rand() % 5) / 5.0 - 1 ) ;
		
		// Mandar mensagem
		cmd_pub.publish(cmd_msg);

		loop_rate.sleep();
	}

	return 0;
}

