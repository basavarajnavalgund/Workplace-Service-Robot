# WOrkplace Service Robot

#### Pre requisites

-  install gazebo 7+
-  ros kinetic


Install all the other required packages

		rosdep install --from-paths . --ignore-src -r -y 


### How to run the gazebo sim
-----------------------------------------------------

To perform SLAM with **gmapping**


	./test_slam.sh



To perform SLAM with **gmapping including obstacle avoidance**


	./obstacle_avoidance.sh


To launch **autonomous navigation**

	./test_navigation.sh
	

To launch **RVIZ**

	rviz

![](images/Screenshot from 2020-06-30 01-03-23.png)

![](images/Screenshot from 2020-06-30 01-04-34.png) 

![](images/Screenshot from 2020-06-30 01-37-21.png)

![](images/Screenshot from 2020-06-30 01-41-29.png)

![](images/t1gz.png)
