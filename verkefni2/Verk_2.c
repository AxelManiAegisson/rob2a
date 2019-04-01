#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
/*----------------------------------------------------------------------------------------------------*\
|*                                     -  2.Hluti Verkefni 2 -                                        *|
|*                                    ROBOTC on VEX 2.0 CORTEX                                        *|
|* 			This program instructs the robot to move straight                    	      *|
|*          																																												  *|
|*                                                                                                    *|
|*         						                                              *|
|       																																															*|
\*----------------------------------------------------------------------------------------------------*/
bool b_f = true;
//+0.1*0.314*360= 11.304
const float BASE_DIST = 500;
void stop_motors(){
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}
void reset_encoders(){
	SensorValue[rightEncoder]=0;
	SensorValue[leftEncoder]=0;
}
void drive(int drivetime, bool b_f){
	int dir = (b_f)? (1):(-1);
	while(drivetime > abs(SensorValue[rightEncoder]))		// Creates an infinite loop, since "true" always evaluates to true
		{
			if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
			{
				// Move Forward
				motor[rightMotor] = 80*dir;		    // Right Motor is run at power level 80
				motor[leftMotor]  = 80*dir;		    // Left Motor is run at power level 80
			}
			else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
			{
				// Turn slightly right
				motor[rightMotor] = 60*dir;		    // Right Motor is run at power level 60
				motor[leftMotor]  = 80*dir;		    // Left Motor is run at power level 80
			}
			else	// Only runs if leftEncoder has counted more encoder counts
			{
				// Turn slightly left
				motor[rightMotor] = 80*dir;		    // Right Motor is run at power level 80
				motor[leftMotor]  = 60*dir;		    // Left Motor is run at power level 60
			}
		}
}

task main()
{
	wait1Msec(100);
	for(int i=1;i<6;i++){
		reset_encoders();
		drive(BASE_DIST*i,true);
		reset_encoders();
		drive(BASE_DIST*i,false);
	}
stop_motors();
}
