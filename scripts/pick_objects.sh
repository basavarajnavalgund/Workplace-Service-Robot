#!/bin/sh
xterm  -e  " roslaunch agv_description agv.launch " &
sleep 5
xterm  -e  " roslaunch agv_description amcl.launch " &
sleep 5
xterm  -e  " rostopic echo /amcl_pose  " &
sleep 5
xterm  -e  " source devel/setup.bash; rosrun pick_objects pick_objects "

