#!/bin/sh
xterm  -e  " roslaunch agv_description agv.launch " &
sleep 5
xterm  -e  " roslaunch agv_description rtabmapping.launch  " &
sleep 5
xterm  -e  " roslaunch agv_description rtabmapping_rviz.launch  " &
sleep 5
xterm  -e  " roslaunch agv_description teleop.launch  "
