#!/bin/sh
xterm  -e  " roslaunch agv_description agv.launch " &
sleep 5
xterm  -e  " roslaunch agv_description gmapping.launch " &
sleep 5
xterm  -e  " roslaunch agv_description teleop.launch "



