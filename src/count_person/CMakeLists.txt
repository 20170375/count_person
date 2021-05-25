cmake_minimum_required(VERSION 3.0.2)
project(count_person)

add_compile_options(-O -Wall -std=c++14 -fpermissive)


find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    darknet_ros_msgs
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    darknet_ros_msgs
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(count_person
    src/count_person.cpp
)
add_dependencies(count_person ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(count_person
    ${catkin_LIBRARIES}
)
