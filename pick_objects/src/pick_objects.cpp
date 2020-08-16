#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

const int max_wait_goal_sub = 5;
int wait_goal_sub = 0;

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  ros::NodeHandle n;

  // Goal Publisher
  ros::Publisher goal_pub = n.advertise<geometry_msgs::Pose>("/target",20);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 0.807;
  goal.target_pose.pose.position.y = -5.09;
  goal.target_pose.pose.orientation.w = 1.0;

  while (goal_pub.getNumSubscribers() < 1 &&
    (wait_goal_sub <= max_wait_goal_sub))
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN("Waiting for add_markers to subscribe for goal position %d / %d",
      wait_goal_sub, max_wait_goal_sub);
    sleep(1);
    wait_goal_sub++;
  }

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal for pickup location");
  ac.sendGoal(goal);

  geometry_msgs::Pose msg;
  msg.position.x = 0.807;
  msg.position.y = -5.09;
  msg.position.z = 0.0;
  msg.orientation.x = 0.0;
  msg.orientation.y = 0.0;
  msg.orientation.z = 0.0;
  msg.orientation.w = 1.0;
  goal_pub.publish(msg);
  ROS_INFO("Publishing goal for pickup location x:%f, y:%f, w:%f",
    msg.position.x,
    msg.position.y,
    msg.orientation.w
    );


  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    //ROS_INFO("Hooray, the base moved 1 meter forward");
    ROS_INFO("Hooray, the robot reached to the pickup location, 5 seconds to go");
    ros::Duration(5.0).sleep();
  }
  else {
    ROS_INFO("The robot failed to reach to the pickup location, exiting");
    ros::Duration(5.0).sleep();
    return 0;
  }

  move_base_msgs::MoveBaseGoal drop_goal;

  // set up the frame parameters
  drop_goal.target_pose.header.frame_id = "map";
  drop_goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  drop_goal.target_pose.pose.position.x = 0.024;
  drop_goal.target_pose.pose.position.y = -16.71;
  drop_goal.target_pose.pose.orientation.w = -0.5;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal for drop off location");
  ac.sendGoal(drop_goal);

  geometry_msgs::Pose drop_msg;
  drop_msg.position.x = 0.024;
  drop_msg.position.y = -16.71;
  drop_msg.position.z = 0.0;
  drop_msg.orientation.x = 0.0;
  drop_msg.orientation.y = 0.0;
  drop_msg.orientation.z = 0.0;
  drop_msg.orientation.w = -0.5;
  goal_pub.publish(drop_msg);
  ROS_INFO("Publishing goal for drop off location x:%f, y:%f, w:%f",
    msg.position.x,
    msg.position.y,
    msg.orientation.w
    );

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("SUCCESS, the robot reached to the drop off location, exiting");
  else
    ROS_INFO("The robot failed to reach to the drop off location, exiting");
  ros::Duration(5.0).sleep();
  return 0;
}
