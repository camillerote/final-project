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
#define WEEK_EVENTS_LENGTH 7

/* DATA STRUCTURES */

typedef struct Event
{
   int hour;
   int minute;
   int month;
   int day;
   int year;

   char *location;
   char *description;

} event_struct;

typedef struct DayAgenda
{
    event_struct dayEvents[ MAX_EVENTS ];
    int numberDayEvents;

} dayAgenda_struct;

/* Function prototypes */

void agendaRunner(void);

int getIntegerOfDay( char *day ); 

void printDayOfWeek( int dayIndex );

void printEvent( event_struct event );

void printDailyAgenda( dayAgenda_struct dailyAgenda );

void printWeeklyAgenda( int dayInt );

void displayEventMenu();

void displayDayEventsMenu( dayAgenda_struct* dayEvents );

int requestDayOfWeek();
 
int requestIntegerFromUser( char* prompt, int min, int max );

event_struct* createEvent();

#endif /* AGENDA_H */
