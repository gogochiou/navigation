#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>


int main(int argc, char **argv){
    ros::init(argc, argv, "goal_pose");
    ROS_INFO("ggggggggg");
    ros::NodeHandle n;
    ros::Publisher goal_pose_set = n.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 1000);
    ros::Rate loop_rate(1);
    geometry_msgs::PoseStamped goal;
    //goal.header.seq = 0;
    //goal.header.stamp.sec = 4358;
    //goal.header.stamp.nsec = 383000000;
    goal.header.frame_id = "map";
    goal.pose.position.x = 0.8;
    goal.pose.position.y = 2;
    goal.pose.position.z = 0;
    goal.pose.orientation.x = 0;
    goal.pose.orientation.y = 0;
    goal.pose.orientation.z = -0.021;
    goal.pose.orientation.w =  1;
    /*while(ros::ok()){
        goal_pose_set.publish(goal);  
        loop_rate.sleep(); 
    }*/
     int time = 0;
    while(ros::ok()){
        if(time <=1){
            time +=1;
            goal_pose_set.publish(goal);  
            ROS_INFO("yayaya");         
        }
        ROS_INFO("nononon");
        loop_rate.sleep(); 
    }
    ros::spinOnce();
    return 0;
}