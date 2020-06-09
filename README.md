# AIA_n4s_2019

Subject:

By now you’ve understood that it’s now your turn to create your own autonomous car. It must be capable of driving on a track without hitting the walls or driving in the wrong direction. In order to help you with this task, several tools are avaible:

• V-REP is a simulator created by Coppelia Robotics. It enables the creation and control of robots. For this project, we have built a virtual track and car that you will use to implement for AI. You will find, further on in this document, how to install/use this software on your machine,

• an API (binary name: n4s). It is a communication interface that offers an array of actions that you can use (start a simulation, set the car motor’s speed, wheel angle,. . . ). You can also use it alone in order to test the communication protocol on the command line. This communication protocol is defined further on,

• a shell script (binary name: pipes.sh) that enables you to connect your program to the API and launch simulations. It’s a binary that you will run in order to test your AI. Its utilization is also presented further on.

Usage:
<ol>
  <li>Start V-REP</li>
  <li>Load scene</li>
  <li>Run ./pipes.sh</li>
</ol>
