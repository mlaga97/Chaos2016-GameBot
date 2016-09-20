#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "Roller.h"
#include "Arm.h"
//#include "CVClient.h"
#include <iostream>

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {

	// Press "Start" Button to Autofire
	if(driver.GetRawButton(8)) {
		//CVRequest c = cvClient.autoAim();

		/* TODO: Re-implement
		 * My idea is to use get an initial angle when the button is
		 * pressed and hold onto it until the the button is released
		 * using a flag variable so as to remain non-blocking.
		 */

	// Manual Control
	} else {
		// Drive
		robotDrive.ArcadeDrive
		(
			-driver.GetRawAxis(1),		// Forward movement
			-driver.GetRawAxis(4)		// Rotational movement
		);

		roller.Set( copilot.GetRawAxis(1) + 0.1 );
	}

	UpdateMotors();

	arm.Set(copilot.GetRawAxis(5));

	Wait(0.005);
}
