#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "Roller.h"
#include "Arm.h"
#include "CVClient.h"
#include <iostream>

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {

	// Check "Start" Button For Autoshoot
	if(driver.GetRawButton(8)) {
		Target target = cvClient.getData();

		float rotation_speed = -0.01*target.x;

		// Threshold
		if(rotation_speed > 0.5)
			rotation_speed = 0.5;
		else if(rotation_speed < -0.5)
			rotation_speed = -0.5;

		std::cout << "ROTATION_SPEED: " << rotation_speed << "\n";

		// Auto Aim
		robotDrive.ArcadeDrive(
			0.0,			// Forward movement
			rotation_speed	// Rotational movement
		);
	} else {
		// Drive
		robotDrive.ArcadeDrive
		(
			-driver.GetRawAxis(1),		// Forward movement
			-driver.GetRawAxis(4)		// Rotational movement
		);
	}

	UpdateMotors();

	roller.Set( copilot.GetRawAxis(1) );
	arm.Set(copilot.GetRawAxis(5));

	Wait(0.005);
}
