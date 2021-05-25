#include "ros/ros.h"
#include <iostream>
#include <std_msgs/Int32.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <darknet_ros_msgs/BoundingBox.h>
#include <cstdlib>

namespace count_person
{
    class CountPerson
    {
        public:
            CountPerson();
            ~CountPerson();

            void callbackNum(const darknet_ros_msgs::BoundingBoxes::ConstPtr &ptr);
            
            void run();

        private:
            ros::Publisher pub_num_;
            ros::Subscriber sub_num_;
            
            ros::NodeHandle nh;

            int count_;
    };
}