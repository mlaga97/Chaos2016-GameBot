#ifndef SRC_ROLLER_H_
#define SRC_ROLLER_H_

#include "WPILib.h"

class Roller
{
  private:
	CANTalon rollerLeft;
	CANTalon rollerRight;

  public:
	Roller( int talon_id, int talon_id2);

	void Set( float speed );
};

#endif /* SRC_ROLLER_H_ */
