#include <cstdint>
#include <cmath>
#include "WPILib.h"
#include "DevBot.h"
#include <iostream>

void DevBot::AutonomousInit() {
	// Setup
	robotDrive.SetSafetyEnabled(false);
	gyro.Reset();
	Timer timer;

	// Reset Timer for loop
	timer.Reset();
	timer.Start();

	// Drive straight for 2 seconds
	while ( timer.Get() < 2 ) {
		robotDrive.ArcadeDrive(-0.20, gyro.GetAngle() * 0.1);
		UpdateMotors();
		Wait(0.005);
	}

	// Stop
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
}

void DevBot::AutonomousPeriodic() {
	Wait(0.005);
}

void DevBot::Turn( float absSpeed, float targetAngle ) {
	float offset;
	float absOffset;
	float speed;

	// Reset the gyro to 0 degrees
	gyro.Reset();
	
	do {
		// Find the offsets for the rest of the math
		offset = gyro.GetAngle() - targetAngle;
		absOffset = std::abs(offset);
		
		// Calculate output speed
		if(offset > 0)
			speed = absSpeed;
		else
			speed = -1 * absSpeed;

		// Turn
		robotDrive.ArcadeDrive(0.0, speed);

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while( absOffset > 1 ); // Repeat until target is reached.

	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
}

void DevBot::Backward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.ArcadeDrive(-Speed, gyro.GetAngle() * 0.1 );
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	timer.Stop();
}

void DevBot::Forward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.ArcadeDrive(Speed, -gyro.GetAngle() * 0.1 );
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	timer.Stop();
}
