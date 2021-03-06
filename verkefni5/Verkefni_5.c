#pragma config(Sensor, in3,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/*----------------------------------------------------------------------------------------------------*\
|*                           									- VERKEFNI 5 -             					                    *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 3 VEX Line Follower Sensors to track a black line on a light(er) surface.       *|
|*  																																														   		*|
\*----------------------------------------------------------------------------------------------------*/
task Stop()
{
	while (vexRT[Btn7D] == 0)
	{

	}
	StopAllTasks();
}

task main()
{
  wait1Msec(2000);

  StartTask(Stop);
  int threshold = 2800;
  //if makes it follow a line if it sees a black line
  while(true)
  {
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      motor[leftMotor]  = 80;
      motor[rightMotor] = 60;
    }

    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      motor[leftMotor]  = 0;
      motor[rightMotor] = 60;
    }
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      motor[leftMotor]  = 60;
      motor[rightMotor] = 0;
    }
  }
}
