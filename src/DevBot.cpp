#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "Roller.h"
#include "Arm.h"
#include "CVClient.h"

DevBot::DevBot():
	// Actual Motor Controllers
	frontLeft(7),
	middleLeft(8),
	rearLeft(9),

	frontRight(10),
	middleRight(11),
	rearRight(12),

	// Fake Motor Controllers
	PWMl(0),
	PWMr(1),
	
	// Controllers
	driver(5),
	copilot(4),
	
	// Pseudo-Subsystems
	roller(13, 14),
	arm(15),
	cvClient(),

	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMl, PWMr)
{
	// Wait for vision server to come up
	// TODO: Avoid this like the plague.
	Wait(60);

	// Computer Vision Setup
	// TODO: Maybe do this somewhere else.
	cvClient.initialize();

	// Other Assorted Setup
	robotDrive.SetExpiration(0.3);
	compressor.Start();
}

// TODO: Check if WPILib is fixed yet.
void DevBot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontLeft.Set(PWMl.Get());
	middleLeft.Set(PWMl.Get());
	rearLeft.Set(PWMl.Get());
	
	frontRight.Set(PWMr.Get());
	middleRight.Set(PWMr.Get());
	rearRight.Set(PWMr.Get());

	roller.Set( copilot.GetRawAxis(1) );
	arm.Set(copilot.GetRawAxis(5));

}

START_ROBOT_CLASS(DevBot);
