#include <cstdint>
#include "WPILib.h"
#include "Roller.h"

Roller::Roller( int talon_id, int talon_id2 ):
	rollerLeft( talon_id ),
	rollerRight( talon_id2 )
{
}

void Roller::Set( float speed ) {
	rollerLeft.Set( -speed );
	rollerRight.Set( speed );
}
