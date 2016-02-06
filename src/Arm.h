/*
 * Arm.h
 *
 *  Created on: Feb 5, 2016
 *      Author: Thomas Travis
 */

#ifndef SRC_ARM_H_
#define SRC_ARM_H_

class Arm
{
private:
	CANTalon armMotor;


public:
	Arm( int Arm_id );

	void Set(float speed);
};

#endif /* SRC_ARM_H_ */
