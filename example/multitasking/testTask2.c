#pragma config(Sensor, dgtl10, pushButton,     sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)

#include "../robheader/myconst.h"
#include "../robfunctions/motorfunctions.c"
#include "mytasks.c"
task main()
{
	StartTask(one,7);
	StartTask(two);
	StartTask(three);
	StartTask(four);
	while(true){

	}
}
