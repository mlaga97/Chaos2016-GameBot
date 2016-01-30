#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

DevBot::DevBot():
	// Actual Motor Controllers
	frontRight(7),
	frontLeft(8),
	rearLeft(9),
	rearRight(10),
	middleLeft(11),
	middleRight(12),

	// Fake Motor Controllers
	PWMl(0),
	PWMr(1),
	
	// Controllers
	driver(5),
	copilot(4),
	
	// Pseudo-Subsystems
	// None yet!
	
	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMl, PWMr)
{
	// Mecanum Boilerplate

	robotDrive.SetInvertedMotor( RobotDrive::kFrontLeftMotor, true );
	robotDrive.SetInvertedMotor( RobotDrive::kRearLeftMotor, true );
	
	// Other Assorted Setup
	robotDrive.SetExpiration(0.3);
	compressor.Start();
}

// TODO: Check if WPILib is fixed yet.
void DevBot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontRight.Set(PWMr.Get());
	frontLeft.Set(PWMl.Get());
	rearLeft.Set(PWMl.Get());
	rearRight.Set(PWMr.Get());
	middleLeft.Set(PWMl.Get());
	middleRight.Set(PWMr.Get());
}

START_ROBOT_CLASS(DevBot);
