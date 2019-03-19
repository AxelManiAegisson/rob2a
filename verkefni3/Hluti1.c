#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port8,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,          rightMotor,    tmotorVex393, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                                     -  1.Hluti Verkefni 3 -                                    	  *|
|*                                    ROBOTC on VEX 2.0 CORTEX                                        *|
|* 									This program lets the user control the robot with a remote controller				  	  *|
|*    		the user can control the arm with a press of a button and open and close the claw.				  *|
|*  	                                                   																					    *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{

	while(1 == 1)
	{
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = 127;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = -127;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = 127;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -127; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}
	}
}
//+++++++
