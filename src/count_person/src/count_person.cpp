#include <count_person.hpp>

namespace count_person
{
    CountPerson::CountPerson()
    {
        count_ = 0;

        pub_num_ = nh.advertise<std_msgs::Int32>("/person_num", 100);

        sub_num_ = nh.subscribe("/darknet_ros/bounding_boxes", 100, &CountPerson::callbackNum, this);
    }

    CountPerson::~CountPerson()
    {   

    }

    void CountPerson::callbackNum(const darknet_ros_msgs::BoundingBoxes::ConstPtr &ptr)
    {
        count_ = 0;
        for (int i=0; i<ptr->bounding_boxes.size(); i++) {
            if (ptr->bounding_boxes[i].Class == "person") {
                count_++;
            }
        }
    }

    void CountPerson::run()
    {
        std_msgs::Int32 si;
        si.data = count_;
        
        ROS_INFO("Person_num : %d", count_);

        pub_num_.publish(si);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "/count_person");

    count_person::CountPerson CP;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        CP.run();

        ros::spinOnce();
        loop_rate.sleep();
    }
}
