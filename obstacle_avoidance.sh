#!/bin/sh
xterm  -e  " roslaunch agv_description agv.launch " &
sleep 5
xterm  -e  " roslaunch agv_description gmapping.launch " &
sleep 5
xterm  -e  " source devel/setup.bash; rosrun motion_plan obstacle_avoidance.py "



