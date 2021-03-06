#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
/*----------------------------------------------------------------------------------------------------*\
|*                                     -  2.Hluti Verkefni 3 -                                    	  *|
|*                                    ROBOTC on VEX 2.0 CORTEX                                        *|
|* This program instructs the robot to move forward 0,5m then do a 90 deg turn left then move another *|
|*  0.5m foward and do a 90deg turn righ then move forward again for 0.5m and it repeats this process 
    14 times   											      *|
|*          																																												  *|
|*                                                                                                    *|
|*          						      					      *|
|*          					                                                      *|
|       																																															*|
\*----------------------------------------------------------------------------------------------------*/
const float BASE_DIST = 600;
void turn(int degrees10,bool counterclock){
	SensorType[in8] = sensorNone;
  wait1Msec(1000);
  SensorType[in8] = sensorGyro;
  wait1Msec(2000);

  while(abs(SensorValue[in8]) < degrees10)
  {
		if (counterclock){
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
		}
		else{
		motor[rightMotor] = -50;
		motor[leftMotor] = 50;
		}
  }

  //Brief brake to stop some drift
  motor[rightMotor] = -5;
  motor[leftMotor] = 5;
  wait1Msec(250);
}

void drive(int dist){
	while(dist > abs(SensorValue[rightEncoder]))		// Creates an infinite loop, since "true" always evaluates to true
		{
			if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
			{
				// Move Forward
				motor[rightMotor] = 80;		    // Right Motor is run at power level 80
				motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
			}
			else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
			{
				// Turn slightly right
				motor[rightMotor] = 60;		    // Right Motor is run at power level 60
				motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
			}
			else	// Only runs if leftEncoder has counted more encoder counts
			{
				// Turn slightly left
				motor[rightMotor] = 80;		    // Right Motor is run at power level 80
				motor[leftMotor]  = 60;		    // Left Motor is run at power level 60
			}
		}
}
void stop_motors(){
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}

void ResetEncoder()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

task main()
{
	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

  ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

  ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,true);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

	ResetEncoder();
	turn(900,false);
	stop_motors();

	ResetEncoder();
	drive(BASE_DIST);
	stop_motors();

}
