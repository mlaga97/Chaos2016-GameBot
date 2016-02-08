/*
 * Arm.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Thomas Travis
 */
#include "WPIlib.h"
#include <Arm.h>

Arm::Arm(int arm_id):
	// TODO Auto-generated constructor stub
	armMotor(arm_id)
{
}

void Arm::Set( float speed ) {
	armMotor.Set( speed );
}


