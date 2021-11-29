/*
 * agenda.h
 */
#ifndef AGENDA_H
#define AGENDA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* CONSTANTS */
#define SIZE 256 /* size of string */
#define MAX_EVENTS 10

/* GLOBAL VARIABLES */

/* DATA STRUCTURES */
typedef struct agenda {
	char events[MAX_EVENTS][SIZE];
	int numOfEvents;
} dailyAgenda;


/* FUNCTIONS */

/* function to find day*/ 
int getIntegerOfDay(char *day);

void printDay(int dayInt);

int runAgendaMaker();

#endif /* AGENDA_H */
