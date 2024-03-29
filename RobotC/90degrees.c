//Initialising Motors
#pragma config(Sensor, S1,     touchSensor,   sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,    sensorEV3_Gyro)
#pragma config(Sensor, S3,     colorSensor,   sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,   sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA, armMotor,      tmotorEV3_Medium, PIDControl,             encoder)
#pragma config(Motor,  motorB, leftMotor,     tmotorEV3_Large,  PIDControl, driveLeft,  encoder)
#pragma config(Motor,  motorC, rightMotor,    tmotorEV3_Large,  PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Author:               Jorik Cronenberg
*/

task main()
{
	long iGrad = 0;
	resetGyro(S2);
	while(iGrad < 90)
	{
		if (iGrad < 60)
		{
			setMotorSpeed(motorB, 100);
			setMotorSpeed(motorC, -100);
		}
		else if (iGrad < 89)
		{
			setMotorSpeed(motorB, 10);
			setMotorSpeed(motorC, -10);
		}
		else
		{
			setMotorSpeed(motorB, 3);
			setMotorSpeed(motorC, -3);
		}
		iGrad = getGyroDegrees(S2);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}
