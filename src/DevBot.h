#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"
#include "Roller.h"
#include "Arm.h"
#include "CVClient.h"

// Main Robot Class
class DevBot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	CANTalon frontLeft;
	CANTalon middleLeft;
	CANTalon rearLeft;

	CANTalon frontRight;
	CANTalon middleRight;
	CANTalon rearRight;

	// Fake Motor Controllers
	// TODO: Check if WPILib is fixed yet.
	TalonSRX PWMl;
	TalonSRX PWMr;

	// Controllers
	Joystick driver;
	Joystick copilot;
	
	// Pseudo-Subsystems
	Roller roller;
	Arm arm;
	CVClient cvClient;

	// Assorted In's and Out's
	AnalogGyro gyro;
	BuiltInAccelerometer accelerometer;
	Compressor compressor;
	RobotDrive robotDrive;

	// Autonomous Switch Inputs
	DigitalInput auto0;
	DigitalInput auto1;
	DigitalInput auto2;
	DigitalInput auto3;
	DigitalInput auto4;
	DigitalInput auto5;
  public:
	// Constructor Method
	DevBot();

	// Various Iterators
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	
	// Various Helper Functions
	void UpdateMotors();
	void Forward( float Speed, float Time );
	void Backward( float Speed, float Time );
	void Turn( float absSpeed, float targetAngle );
	int AutoSwitch();
};

#endif /* SRC_DEVBOT_H_ */
