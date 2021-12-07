/*
 * main.c
 */

#include "main.h"
#include "agenda.h"
#include <stdbool.h>

int main( void ) 
{
    // Local Variables

    dailyAgenda agendas[ 7 ];    // Daily agenda for week (0-6 Sun-Sat)
    bool done = false;           // Assume user not done
    int menuOption = 0;
    char day[ 20 ];

    event* anEvent;

    anEvent = createEvent();

    printEvent( anEvent );
    // Initialize number of events for each day
/*
    for ( int i = 0; i < 7; i++ )
    {
        agendas[ i ].numOfEvents = 0;
    }          

    // Keep allowing user to enter menu options for the agenda

    while ( !done )
    {
        // Display event menu

        displayEventMenu();
	
        // Get user menu option

	scanf( "%d", &menuOption );
	
	switch ( menuOption )
        {
	   case 1: agendaIndex++;
                   agenda[ agendaIndex ] = createEvent();
	           break;

           case 2: editEvent();
                   break;
                
           case 3: deleteEvent(); 
	           break;
		
           case 4: printEvent(); 
	           break;
		
           case 5: done = true;     // Exit application
	           break;

           default: printf( "Invalid menu option: valid 1-5!" );
	}
    }
    */
}
