/*
 * main.c
 */

#include "main.h"
int AgendaMaker(void) 
{
    // Local Variables

    dailyAgenda agendas[ 7 ];    // Daily agenda for week (0-6 Sun-Sat)
    int forever = 1;
    int menuOption = 0;
    char day[ 20 ];

    // Initialize number of events for each day

    for ( int i = 0; i < 7; i++ )
    {
        agendas[ i ].numOfEvents = 0;
    }          

    // Keep allowing user to enter menu options for the agenda

    while ( forever )
    {
        // Display event menu

        displayEventMenu();
	
        // Get user menu option

	scanf( "%d", &menuOption );
	
	switch ( menuOption )
        {
		case 1: createEvent();
                        break;
		case 2: editEvent();
                        break;
                case 3: displayEvent(); 
			break;
		case 4:
			return 0;
		
	}
	int currentday = getIntegerOfDay(day);

	dailyAgenda currentAgenda = Agendas[currentday]; 

	printf("Press 1 to add event,\n 2 to view events,\n 3 to delete event.\n");

	switch (selection)
	{
		case 1:{
			event newEvent;
			char time[SIZE];
			char date[SIZE];
			char location[SIZE];
			char description[SIZE];
			printf("Time:\n");
			scanf("%s", time);
			printf("Date:\n");
			scanf("%s", date);
			printf("Loaction:\n");
			scanf("%[^\n]%*c", location);
			printf("Description:\n");
			scanf("%[^\n]%*c", description);
			}
			break;
 
		 case 2:
			for(int i=0; i<currentAgenda.numOfEvents; i++){
				printEvent(currentAgenda.arrayEvent[i]);
			} 
	}
    return(SUCCESS);
}
