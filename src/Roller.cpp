#include "WPILib.h"
#include "roller.h"

Roller::Roller( int talon_id, int talon_id2, int topLS_port, int bottomLS_port ):
	rollerLeft( talon_id ),
	rollerRight( talon_id2 ),
	topLS( topLS_port ),
	bottomLS( bottomLS_port )
{
}

void Roller::Set( float speed ) {

	// Check the limit switches first
	if( topLS.Get() ) {

		// If the top limit switch is tripped, only go down.
		if( speed < 0 ) {
			rollerLeft.Set( speed );
			rollerRight.Set( speed );
		} else {
			rollerLeft.Set( 0 );
			rollerRight.Set( 0 );
		}

	} else if( bottomLS.Get() ) {

		// If the bottom limit switch is tripped, only go up.
		if( speed > 0 ) {
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
