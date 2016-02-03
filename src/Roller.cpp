#include <cstdint>
#include "WPILib.h"
#include "roller.h"

Roller::Roller( int talon_id, int talon_id2, int LS_Port):
	rollerLeft( talon_id ),
	rollerRight( talon_id2 ),

	LS( LS_Port )
{

}

void Roller::Set( float speed ) {

	// Check the limit switches first
	if( LS.Get() ) {

		// If the top limit switch is tripped, only go down.
		if( speed < 0 ) {
			rollerLeft.Set( speed );
			rollerRight.Set( speed );
		} else {
			rollerLeft.Set( 0 );
			rollerRight.Set( 0 );
		}

	} else {

			// Otherwise, go whatever speed is given.
			rollerLeft.Set( speed );
			rollerRight.Set( speed );

		}

	}


