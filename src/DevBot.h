#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"

// Main Robot Class
class DevBot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	CANTalon frontRight;
	CANTalon frontLeft;
	CANTalon rearLeft;
	CANTalon rearRight;

	// Fake Motor Controllers
	// TODO: Check if WPILib is fixed yet.
	TalonSRX PWMfr;
	TalonSRX PWMfl;
	TalonSRX PWMrl;
	TalonSRX PWMrr;

	// Controllers
	Joystick driver;
	Joystick copilot;
	
	// Pseudo-Subsystems
	// None yet!
	
	// Assorted In's and Out's
	Gyro gyro;
	BuiltInAccelerometer accelerometer;
	Compressor compressor;
	RobotDrive robotDrive;
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
};

#endif /* SRC_DEVBOT_H_ */
