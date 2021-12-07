/*
 * agenda.h
 */
#ifndef AGENDA_H
#define AGENDA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
/* CONSTANTS */

#define SIZE 256 
#define MAX_EVENTS 3

/* DATA STRUCTURES */

typedef struct Event
{
   int hour;
   int minute;
   int month;
   int day;
   int year;

   char location[ SIZE ];
   char description[ SIZE ];

} event_struct;

typedef struct DayAgenda
{
    event_struct dayEvents[ MAX_EVENTS ];

    int numberDayEvents;

} dayAgenda_struct;

dayAgenda_struct weekEvents[ 7 ];

/* Function prototypes */

int getIntegerOfDay( char *day ); 

void printDayOfWeek( int dayIndex );

void printEvent( event_struct* anEvent );

void printDailyAgenda( dayAgenda_struct dailyAgenda );

void printWeeklyAgenda( int dayInt );

void displayEventMenu();

void displayDayEventsMenu( dayAgenda_struct* events );

int requestDayOfWeek();
 
int requestIntegerFromUser( char* prompt, int min, int max );

event_struct* createEvent();

#endif /* AGENDA_H */
