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
#include <ctype.h>

/* CONSTANTS */

#define SIZE 256 
#define MAX_EVENTS 3
#define WEEK_EVENTS_LENGTH 7

/* DATA STRUCTURES */

//Structure to hold information about a single event
typedef struct Event
{
    int hour;
    int minute;
    int month;
    int day;
    int year;

    char location[100];
    char description[200];

} event_struct;


//Structure to hold 3 single events that represent a day
typedef struct DayAgenda
{
    event_struct dayEvents[ MAX_EVENTS ];
    int numberDayEvents;

} dayAgenda_struct;

/* Function prototypes */

void agendaRunner(void);

void initialAgendaDefault(dayAgenda_struct []);

void displayEventMenu();

void createEvent( dayAgenda_struct* newEvent, int choice);

int requestIntegerFromUser( char* prompt, int min, int max );

int getIntegerOfDay( char *day );

int getDayOfWeek(void);

void lowerCase(char *day);

void printDayOfWeek( int dayIndex );

void printWeeklyAgenda( dayAgenda_struct agendas[]);

void printEvent( event_struct event );

void printDailyAgenda(dayAgenda_struct agendas[], int day);

void editEvent(event_struct *event);

void partialEditEvent(event_struct *event);

void fullEditEvent(event_struct *event);

void deleteEvent(event_struct *event);

#endif /* AGENDA_H */
