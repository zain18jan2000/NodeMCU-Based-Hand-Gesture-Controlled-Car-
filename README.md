# NodeMCU-Based-Hand-Gesture-Controlled-Car-
A NodeMCU Based Car where the Computer Vision technique is used for controlling

<H1>PRE-REQUISITES:</H1>  
1) Basic Knowledge of Computer Vision <br>
2) Baic knoledge of Client-Server Relationship <br>
3) Programming experience in C++ (for Arduino IDE) and Python. <br>

<h1>REQUIRED SOFTWARES:</h1>
1) ARDUINO IDE <br>
2) PYTHON IDE (I'll prefer to use jupyter notebook for the purpose  of ease) <br>

<h1>DEPENDENCIES:</h1>
<h3>FOR  PYTHON</h3>
1) OpenCV <br>
2) Mediapipe <br>
3) httplib2 <br>
<h3>FoR C++ (ARDUINO IDE)</h3>
  ESP8266WiFi.h

<h1>REQUIRED COMPONENTS</h1>
1) NodeMCU <br>
2) Motor driver L298N <br>
3) BO MOTOR with wheels x 2 <br>
4) Jumper wires <br>
5) Battery
6) LM7805

<H1>HOW TO IMPLEMENT? </H1>
The main idea to implement a nodeMCU based hand gesture controlled car is that, the nodeMCU in the car is programmed to act as server, which will control the motion of the car on the basis of the command or request it will recieves. Here the nodeMCU will be used as an access point. After that I will need to create a python program which will perform the following important task, <br>
1) To detect the Hand and then identify its gesture using computer vision techniques. <br>
2) To act as client and on the basis of hand gesture it will send a request to server i.e nodeMCU using 'GET' method.  
  
<h1>CONNECTION DIAGRAM:</h1>


![nodeMcu](https://user-images.githubusercontent.com/82854685/158703275-89538302-555b-4111-91e2-dd6359183aeb.JPG)



<h1>VIDEO DEMO: </h1>
https://drive.google.com/file/d/192WbUxf8NpuVT6cIU62cTkyCM23feeq9/view?usp=sharing
