/*
 * roller.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Thomas Travis
 */

#ifndef SRC_ROLLER_H_
#define SRC_ROLLER_H_

class Roller {

private:
	CANTalon rollerLeft;
	CANTalon rollerRight;

	DigitalInput topLS;
	DigitalInput bottomLS;


public:
	Roller( int talon_id, int talon_id2, int topLS_port, int bottomLS_port );

	void Set( float speed );

};



#endif /* SRC_ROLLER_H_ */
