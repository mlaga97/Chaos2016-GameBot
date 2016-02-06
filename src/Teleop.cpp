#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "Roller.h"
#include "Arm.h"

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {
	// Drive
	robotDrive.ArcadeDrive
	(
		driver.GetRawAxis(1),		// Forward movement
		-driver.GetRawAxis(4)		// Rotational movement
	);

	UpdateMotors();

	roller.Set( copilot.GetRawAxis(1) );
	arm.Set(copilot.GetRawAxis(5));

	Wait(0.005);
}
