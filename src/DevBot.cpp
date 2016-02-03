#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "roller.h"


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
	roller( 13, 14, 0 ),

	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMl, PWMr)
{
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

}

START_ROBOT_CLASS(DevBot);
