cmake_minimum_required(VERSION 2.8.3)
project(lecture_nodes)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES lecture_nodes
   CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)


## Declare a C++ executable
add_executable(aula1_node src/aula1_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(aula1_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(aula1_node
   ${catkin_LIBRARIES}
)
