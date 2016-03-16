#include <cstdint>
#include <cmath>
#include "WPILib.h"
#include "DevBot.h"

void DevBot::AutonomousInit() {
	// Autonomous Modes
	//	0 = Do nothing					(0.0s)
	//	1 = Move forward to defense		(2.5s)
	//	2 = Breach defense				(7.0s)
	//	3 = Turn towards goal			(9.0s)
	//  4 = Move towards goal			(11.0s)
	//	5 = Shoot at goal				(13.0s)
	//	6 = Enable vision				(15.0s)
	int AutoMode = 6;

	// Setup
	robotDrive.SetSafetyEnabled(false);

	// Move Forward
	if(1 <= AutoMode) {
		Forward(0.5, 2.5);
	}

	// Breach Defense
	if(2 <= AutoMode) {
		Forward(0.6, 0.5);
		Forward(0.5, 4);
	}

	// Turn towards goal
	if(3 <= AutoMode) {
		Turn(0.5, -60);
	}

	// Move towards goal
	if(4 <= AutoMode) {
		Forward(0.5, 2);
	}
	
	// Use computer vision to Aim
	if(6 <= AutoMode) {
		c = cvClient.autoAim();
		Turn(0.5, c.angle_offset);
	}
	
	// Shoot the ball
	if(5 <= AutoMode) {
		roller.Set(-1);
		Wait(1);
		roller.Set(0);
	}
}

void DevBot::AutonomousPeriodic() {
	Wait(0.005);
}

void DevBot::Turn( float absSpeed, float targetAngle ) {
	float angle;
	float offset;
	float speed;

	// Reset the gyro to 0 degrees
	gyro.Reset();
	
	do {
		// Find the offsets for the rest of the math
		angle = gyro.GetAngle();
		offset = angle - targetAngle;
		
		// Calculate output speed
		if(offset > 0)
			speed = -absSpeed;
		else
			speed = absSpeed;

		// Turn
		robotDrive.ArcadeDrive(0.0, speed);
		UpdateMotors();

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while( abs(offset) > 1 ); // Repeat until target is reached.

	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
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
		UpdateMotors();
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
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
		UpdateMotors();
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
	timer.Stop();
}
