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

void agendaRunner(void); // Camille - Anika we worked on it together since the large switch staement included both of our parts

void initialAgendaDefault(dayAgenda_struct []); //Camille

void displayEventMenu(); //Anika

void createEvent( dayAgenda_struct* newEvent, int choice);// Camille

int requestIntegerFromUser( char* prompt, int min, int max ); //Camille 

int getIntegerOfDay( char *day ); //Camille 

int getDayOfWeek(void); //Camille 

void lowerCase(char *day); //Camille 

void printDayOfWeek( int dayIndex ); //Anika

void printWeeklyAgenda( dayAgenda_struct agendas[]); //Anika

void printEvent( event_struct event );  //Camille 

void printDailyAgenda(dayAgenda_struct agendas[], int day); //Anika  

void editEvent(event_struct *event); //Camille 

void partialEditEvent(event_struct *event); //Anika

void fullEditEvent(event_struct *event); //Anika

void deleteEvent(event_struct *event); //Anika 

#endif /* AGENDA_H */
