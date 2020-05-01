#Self-Driving Car

Small scale autonomous vehicle which features sensory suite integration (lidar, pixy camera) with Raspberry Pi and Ardunio microcontrollers, DC motors with motor controllers

* Built on a pre-fabricated chasis
* Sensor fusion integrates RPLIDAR and Pixy Cam with Raspberry PI Model B+ for object detection and localization
* Motor controllers are interfaced with Arduino Mega to control speed through pulse width modulation
* ROS (Robotic Operating System) is used to broadcast and receive data from sensors for decision making
* PID control is implemeted for overall stability
