#!/bin/sh
xterm  -e  " roslaunch agv_description agv.launch " &
sleep 5
xterm  -e  " roslaunch agv_description amcl.launch " &
sleep 5
xterm  -e  " rostopic echo /amcl_pose  "


