/*
 * agenda.c
 */

#include "agenda.h"

/* GLOBAL VARIABLES */
dayAgenda_struct weekEvents[WEEK_EVENTS_LENGTH];

/* Function prototypes */

void agendaRunner(void) 
{
    //array that will hold events in a week
    dayAgenda_struct agendas[WEEK_EVENTS_LENGTH];

    bool done = false;
    int menuOption = 0;
    int dayOfWeek;
    int choice;

    //begin with an empty agenda
    initialAgendaDefault(agendas);

    //modify the weekly agenda by adding, editing, and deleting events until
    //user is done
    while ( !done )
    {
        //display main menu to add, edit and delete events
        displayEventMenu();
        scanf( "%d", &menuOption );

        //perform chosen menu option
        switch ( menuOption )
        {
        case 1: //create event by obtaining the day of the week and event to be
                //added to the agenda
            dayOfWeek = getDayOfWeek( );

            if(dayOfWeek == -1)
            {
                printf("\t\nERROR: Invalid day of week entered. Try again!\n\a");
                break;
            }

            choice = requestIntegerFromUser( "Enter event to edit [1-3]: ",   1, 3 );
            createEvent(&agendas[dayOfWeek], choice-1);
            break;

        case 2://edit an event by obtaining the day of the week and the event to be
            //edited partially or fully, a menu is given to user edit the appropriate
            //data
            dayOfWeek = getDayOfWeek( );

            if(dayOfWeek == -1)
            {
                printf("\t\nERROR: Invalid day of week entered. Try again!\n\a");
                break;
            }

            choice = requestIntegerFromUser( "Enter event to edit [1-3]: ",   1, 3 );

            editEvent(&agendas[dayOfWeek].dayEvents[choice-1]);
            break;

        case 3://delete an event by obtaining the day of the week and the event to be
            //deleted
            dayOfWeek = getDayOfWeek( );

            if(dayOfWeek == -1)
            {
                printf("\t\nERROR: Invalid day of week entered. Try again!\n\a");
                break;
            }

            choice = requestIntegerFromUser( "Enter event to edit [1-3]: ",   1, 3 );
            deleteEvent(&agendas[dayOfWeek].dayEvents[choice-1]);
            break;

       case 4: //display the information of a single event, events in a day or all events
            // in a week, user chooses an option
            printf("\t1. Print Single Event\n"
                   "\t2. Print Day Events\n"
                   "\t3. Print Week Events\n\n");
            choice = requestIntegerFromUser( "Enter choice [1-3]: ",   1, 3 );

            switch(choice)
            {

                case 1: //display a single event in a particular day
                    dayOfWeek = getDayOfWeek( );

                    if(dayOfWeek == -1)
                    {
                        printf("\t\nERROR: Invalid day of week entered. Try again!\n\a");
                        break;
                    }

                    choice = requestIntegerFromUser( "Enter event [1-3]: ",   1, 3 );

                    printEvent(agendas[dayOfWeek].dayEvents[choice-1]);

                    break;
                case 2://display the events in a particular day
                    dayOfWeek = getDayOfWeek( );

                    if(dayOfWeek == -1)
                    {
                        printf("\t\nERROR: Invalid day of week entered. Try again!\n\a");
                        break;
                    }

                    printDailyAgenda(agendas, dayOfWeek);
                    break;
                case 3: //display all events in a week
                    printWeeklyAgenda(agendas);
                    break;
           }
           break;

       case 5: //end of editing the agenda
            printf("\n\t\tGoodbye!\n\n");
            done = true;
            break;

        default:
            printf( "\nERROR: Invalid menu option. Try again with valid values 1-5!\n" );
        }
    }
   
}




//displays event menu
void displayEventMenu()
{
    printf( "\n\n\t\t----- Event Menu -----\n" );
    printf( "\t1. Create event\n"      );
    printf( "\t2. Edit event\n"        );
    printf( "\t3. Delete event\n"        );
    printf( "\t4. Display event\n"     );
    printf( "\t5. Exit application\n"  );
    printf("\n\t>>  ");
}

//initializes the agenda array to known initial values of 0 and empty arrays
void initialAgendaDefault(dayAgenda_struct agendas[])
{
    for (int i=0; i< WEEK_EVENTS_LENGTH; i++)
    {
        for (int j=0; j < MAX_EVENTS; j++)
        {
            agendas[i].dayEvents[j].year = 0;
            agendas[i].dayEvents[j].month = 0;
            agendas[i].dayEvents[j].day = 0;
            agendas[i].dayEvents[j].hour = 0;
            agendas[i].dayEvents[j].minute = 0;

            strcpy(agendas[i].dayEvents[j].location, "TEST TEST TEST");
            strcpy(agendas[i].dayEvents[j].description,"TBA");
        }
    }
}

//initializes an event with data entered by user
void createEvent( dayAgenda_struct* newEvent, int choice )
{
    char str[200];
    printf( "\n------------ Time format --------------\n" );
    newEvent->dayEvents[choice].hour = requestIntegerFromUser( "Enter hour [0-23]: ",   0, 23 );
    newEvent->dayEvents[choice].minute = requestIntegerFromUser( "Enter minute [0-59]: ", 0, 59 );

    // Request Date from user

    printf( "\n------------ Date format -----------\n" );
    newEvent->dayEvents[choice].month  = requestIntegerFromUser( "Enter month [1-12]: ",   1, 12 );
    newEvent->dayEvents[choice].minute = requestIntegerFromUser( "Enter day [1-31]: ",     1, 31 );
    newEvent->dayEvents[choice].year   = requestIntegerFromUser( "Enter year [2021 - 2025]: ",  2021, 2025 );

    // Request location from user
    gets();
    printf( "Location[input less than 100 characters]: " );
    fgets(str, 99, stdin);
    strcpy(newEvent->dayEvents[choice].location, str);

    // Request description from user
    printf( "Description:[input less than 200 characters] " );
    fgets(str, 199, stdin);
    strcpy(newEvent->dayEvents[choice].description, str);

}

//obtains an integer from user and validates it to be in given range
int requestIntegerFromUser( char* prompt, int min, int max )
{
    int  number = 0;
    bool validInput = false;

    // Request valid integer from user
    while ( !validInput )
    {
        printf( "%s ", prompt );
        scanf( "%d", &number );

        if ( number >= min && number <= max )
            validInput = true;
        else
            printf( "\n\t\aERROR: Invalid input -- must be in range [%d - %d].Try again!\n\n", min, max );
    }

    return number;
}

//converts a string to all lower case
void lowerCase(char *day)
{
    while(*day != '\0')
    {
        *day = tolower(*day);
        day++;
    }
}

//converts the name of a day to an integer
int getIntegerOfDay( char *day )
{
    // Local Variables
    int dayIndexOfWeek = -1;        // Assume index not found

    // Compare user input to return day index of week - worry about case
    if ( strcmp( day, "sunday" ) == 0 )
        dayIndexOfWeek = 0;
    else if ( strcmp(  day, "monday" ) == 0 )
        dayIndexOfWeek = 1;
    else if ( strcmp(  day, "tuesday" )  == 0 )
        dayIndexOfWeek = 2;
    else if ( strcmp(  day, "wednesday"  ) == 0 )
        dayIndexOfWeek = 3;
    else if ( strcmp(  day, "thursday"  ) == 0 )
        dayIndexOfWeek = 4;
    else if ( strcmp(  day, "friday" ) == 0 )
        dayIndexOfWeek = 5;
    else if ( strcmp(  day, "saturday") == 0 )
        dayIndexOfWeek = 6;

    return dayIndexOfWeek;
}

//obtains the name of a day in a week and returns it as an integer
int getDayOfWeek(void)
{
    char userDay[10];
    int dayOfWeek;
    printf("Enter day of the week (Sunday - Saturday): ");
    scanf("%s19", userDay);

    lowerCase(userDay);

    dayOfWeek = getIntegerOfDay(userDay);

    return dayOfWeek;
}

//displays the name of a day when the input is an integer
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

//displays the information of a single event
void printEvent( event_struct event )
{
    printf( "\n       Time: %d:%d\n",    event.hour, event.minute );
    printf( "       Date: %d/%d/%d\n", event.month,
            event.day, event.year );
    printf( "   Location: %s\n",       event.location    );
    printf( "Description: %s\n",       event.description );
}

//displays the information of the events on a single day
void printDailyAgenda(dayAgenda_struct agendas[], int day)
{
    for ( int i = 0; i < MAX_EVENTS; i++ )
    {
        printEvent(agendas[day].dayEvents[i]);
    }
}

//displays the information of all events in a week
void printWeeklyAgenda( dayAgenda_struct agendas[] )
{
    printf("\n\n");
    for (int i=0; i< WEEK_EVENTS_LENGTH; i++)
    {
        printDayOfWeek( i );
        for (int j=0; j < MAX_EVENTS; j++)
        {
            printEvent(agendas[i].dayEvents[j]);
            printf("\n");
        }

        printf("\n\n");
    }
}

//allows the user to make changes to an event
void editEvent( event_struct *event )
{
    int choice;

    printf("\n\tEdit Event Menu\n"
           "\t1. Edit an event partially\n"
           "\t2. Edit an event entirely\n"
           "\t3. Exit Edit\n");
    choice = requestIntegerFromUser(">>  ", 1,3);

    switch(choice)
    {
    case 1:
        partialEditEvent(event);
        break;
    case 2:
        fullEditEvent(event);
        break;
    case 3:
        printf("\n\tGoing back to main menu\n");
        break;
    }
}

//edits a single event partially
void partialEditEvent(event_struct *event)
{
    int choice;
    char str[200];
    printf("\n\tWhat would you like to edit?\n"
           "\n\t1. Time"
           "\n\t2. Date"
           "\n\t3. Location"
           "\n\t4. Description"
           "\n\t5. Done\n\t");
    choice = requestIntegerFromUser(">>  ", 1,5);

    while(choice != 5)
    {
        switch(choice)
        {
        case 1:
            printf( "\n------------ Edit Time --------------\n" );
            event->hour = requestIntegerFromUser( "Enter hour [0-23]: ",   0, 23 );
            event->minute = requestIntegerFromUser( "Enter minute [0-59]: ", 0, 59 );
            break;
        case 2:
            printf( "\n------------ Edit Date -----------\n" );
            event->month  = requestIntegerFromUser( "Enter month [1-12]: ",   1, 12 );
            event->minute = requestIntegerFromUser( "Enter day [1-31]: ",     1, 31 );
            event->year   = requestIntegerFromUser( "Enter year [2021 - 2025]: ",  2021, 2025 );
            break;
        case 3:
            gets();
            printf( "\n------------ Edit Location -----------\n" );
            fgets(str, 99, stdin );
            strcpy(event->location, str);
            break;
        case 4:
            gets();
            printf( "\n------------ Edit Description -----------\n" );
            fgets(str, 199, stdin );
            strcpy(event->description, str);
            break;
        }
        printf("\n\tWhat would you like to edit?\n"
               "\n\t1. Time"
               "\n\t2. Date"
               "\n\t3. Location"
               "\n\t4. Description"
               "\n\t5. Done\n\t");
        choice = requestIntegerFromUser(">>  ", 1,5);

    }
}

//edits all information in a single event
void fullEditEvent(event_struct *event)
{
    char str[200];
    printf( "\n------------ Edit Time hh:mm --------------\n" );
    event->hour = requestIntegerFromUser( "Enter hour [0-23]: ",   0, 23 );
    event->minute = requestIntegerFromUser( "Enter minute [0-59]: ", 0, 59 );

    // Request Date from user

    printf( "\n------------ Date format mm:dd:yy -----------\n" );
    event->month  = requestIntegerFromUser( "Enter month [1-12]: ",   1, 12 );
    event->minute = requestIntegerFromUser( "Enter day [1-31]: ",     1, 31 );
    event->year   = requestIntegerFromUser( "Enter year [2021 - 2025]: ",  2021, 2025 );

    // Request location from user
    gets();
    printf( "Location: " );
    fgets(str, 99, stdin );
    strcpy(event->location, str);

    // Request description from user

    printf( "Description: " );
    fgets(str, 199, stdin );
    strcpy(event->description, str);
}

//deletes the information of a single event by clearing the data by placing
//0s and empty strings
void deleteEvent( event_struct *event )
{
    event->hour = 0;
    event->minute = 0;
    event->month  = 0;
    event->minute = 0;
    event->year   = 0;
    strcpy(event->location, " ");
    strcpy(event->description, " ");
}
