/*
 * agenda.c
 */

#include "agenda.h"

/* GLOBAL VARIABLES */
dayAgenda_struct weekEvents[WEEK_EVENTS_LENGTH];

/* Function prototypes */

void agendaRunner(void) {

    // Local Variables

    dayAgenda_struct agendas[WEEK_EVENTS_LENGTH];    // Daily agenda for week (0-6 Sun-Sat)
    bool done = false;           // Assume user not done
    int menuOption = 0;
    char day[ 20 ];

    event_struct event;
    event_struct* anEvent;

   /* initialize weekEvents */
for (int i=0; i< WEEK_EVENTS_LENGTH; i++) {

    dayAgenda_struct das;

    event_struct dayEvents[MAX_EVENTS];

    for (int j=0; j<MAX_EVENTS; j++) {
        event_struct es;
        es.hour = 24;
        // es.location = (char *) malloc(SIZE * sizeof(char));
        es.location = "TEST TEST TEST";

        dayEvents[j] = es;

    }
    weekEvents[i] = das;
}

for (int i=0; i< WEEK_EVENTS_LENGTH; i++) {
    dayAgenda_struct das = weekEvents[i];

    event_struct dayEvents[MAX_EVENTS];

    for (int j=0; j<MAX_EVENTS; j++) {
        event_struct es = dayEvents[j];

        printf("(%d,%d) event_struct.hour = %d; event_struct.location = %s\n", i,j,es.hour,es.location);

    }
    weekEvents[i] = das;
}


    anEvent = createEvent();
/*
    //event = anEvent;

    printEvent( event );
    // Initialize number of events for each day

    for ( int i = 0; i < 7; i++ )
    {
        agendas[i].numberDayEvents = 0;
    }          

    // Keep allowing user to enter menu options for the agenda

   int dayIndex = 0;

   while ( !done )
   {
      // Display event menu
      displayEventMenu();

      // Get user menu option
      scanf( "%d", &menuOption );
	
      switch ( menuOption )
      {
         case 1:
            dayIndex++;
            agendas[dayIndex] = createEvent();
            break;

         case 2:
            editEvent();
            break;
   
         case 3:
            deleteEvent(); 
            break;
         
         case 4:
            printEvent(); 
            break;
         
         case 5:
            done = true;     // Exit application
            break;
         
         default: printf( "Invalid menu option: valid 1-5!" );
      }
   }
*/
}

int getIntegerOfDay( char *day ) 
{
    // Local Variables

    int dayIndexOfWeek = -1;    	// Assume index not found
    
    // Compare user input to return day index of week - worry about case

    if ( strcmp( day, "sunday" ) == 0 )
        dayIndexOfWeek = 0;

    else if ( strcmp( day, "monday" ) == 0 )
       dayIndexOfWeek = 1;

    else if ( strcmp( day, "tuesday" )  == 0 )
       dayIndexOfWeek = 2;

    else if ( strcmp( day, "wednesday" ) == 0 )
       dayIndexOfWeek = 3;

    else if ( strcmp( day, "thursday" ) == 0 )
       dayIndexOfWeek = 4;

    else if ( strcmp( day, "friday" ) == 0 )
       dayIndexOfWeek = 5;

    else if ( strcmp( day, "saturday") == 0 )
       dayIndexOfWeek = 6;

    return dayIndexOfWeek;
}

void printDayOfWeek( int dayIndexOfWeek )
{	
    if ( dayIndexOfWeek == 0 )
       printf( "-------Sunday-------\n" );
	
    else if ( dayIndexOfWeek == 1 ) 
       printf( "-------Monday-------\n" );
	
    else if ( dayIndexOfWeek == 2 ) 
       printf( "-------Tuesday-------\n" );

    else if ( dayIndexOfWeek == 3 )
       printf( "-------Wednesday-------\n" );

    else if ( dayIndexOfWeek == 4 )
       printf( "-------Thursday-------\n" );

    else if ( dayIndexOfWeek == 5 )
       printf( "-------Friday-------\n" );
    
    else   //  if ( dayIntOfWeek == 6 ) 
       printf("-------Saturday-------\n");
}

void printEvent( event_struct event )
{
    printf( "       Time: %d:%d\n",    event.hour, event.minute );
    printf( "       Date: %d/%d/%d\n", event.month, 
                                       event.day, event.year );
    printf( "   Location: %s\n",       event.location    );
    printf( "Description: %s\n",       event.description );
}

void printDailyAgenda( dayAgenda_struct dailyAgenda )
{	
    for ( int i = 0; i < dailyAgenda.numberDayEvents; i++ )
    {
        printDayOfWeek( i );
        printEvent( dailyAgenda.dayEvents[ i ] );
        printf( "\n" );
    }
}

void printWeeklyAgenda( int dayIndexOfWeek )
{	
    for ( int i = 0; i < 7; i++ )
    {
        printDailyAgenda( weekEvents[ i ]  );
    }
}

void displayEventMenu()
{
    printf( "----- Event Menu -----/n" );
    printf( "\n"                       );
    printf( "  1. Create event\n"      );
    printf( "  2. Edit event\n"        );
    printf( "  3. Display event\n"     );
    printf( "  4. Exit application\n"  );
}

void displayDayEventsMenu( dayAgenda_struct* dayPtr )
{
    printf( "----- Day Events Menu -----\n" );
    printf( "\n"                       );

    for ( int i = 0; i < dayPtr->numberDayEvents; i++ )
    {
        //if ( /* there is an event for this index */ )
           printEvent( dayPtr->dayEvents[ i ] );
    }
}

int requestDayOfWeek()
{
    // Local Variables

    int dayOfTheWeekIndex = -1;
    bool validInput = false;     // Assume invalid input

    // Request day of the week index and validate 

    while ( !validInput )
    {
        // Valid is 0-6

        printf( "What day are you interested (exp:Sunday-0): " );
        scanf( "%d", &dayOfTheWeekIndex );

        // Verify so user receives errror message

        if ( dayOfTheWeekIndex >= 0 && dayOfTheWeekIndex <= 6 )
           validInput = true;
        else
           printf( "Invalid day of the weeks, only 0-6 is valid!" );
    }

    return dayOfTheWeekIndex;
}
 
int requestIntegerFromUser( char* prompt, int min, int max )
{
    // Local Variables

    int  number = 0;
    bool validInput = false;     // Assume invalid input

    // Request valid integer from user

    while ( !validInput )
    {
        printf( "%s: ", prompt );
        scanf( "%d", &number );

        if ( number >= min && number <= max )
           validInput = true;
        else
           printf( "Invalid input -- must be in range [%d-%d]", min, max );
    }

    return number;
}

event_struct* createEvent()
{
    // Local Variables

    //event_struct* newEvent;

    // Allocate memory for the event structure

    event_struct *newEvent = (event_struct *) malloc( 1 * sizeof( event_struct ) ); 

    // Request time from user

    printf( "------------ Time format hh:mm --------------\n" );
    newEvent->hour   = requestIntegerFromUser( "Enter hour [0-23]: ",   0, 23 );
    newEvent->minute = requestIntegerFromUser( "Enter minute [0:59]: ", 0, 59 );

    // Request Date from user

    printf( "------------ Date format mm:dd:yy -----------\n" ); 
    newEvent->month  = requestIntegerFromUser( "Enter month [1-12]: ",   1, 12 );
    newEvent->minute = requestIntegerFromUser( "Enter day [1-31]: ",     1, 31 );
    newEvent->year   = requestIntegerFromUser( "Enter year [1-31]: ",     1, 31 );

    // Request location from user

    printf( "Location: " );
    scanf( "%[^\n]%*c", newEvent->location );

    // Request description from user
 
    printf( "Description: " );
    scanf( "%[^\n]%*c", newEvent->description );

    return newEvent;
}

void deleteEvent()
{

}

void editEvent()
{

}

