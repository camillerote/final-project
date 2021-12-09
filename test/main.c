#include <stdio.h>
#include <stdlib.h>

#define SIZE 256
#define MAX_EVENTS 3
#define WEEK_EVENTS_LENGTH 7

#define SUCCESS 0


int main(void) {

    

typedef struct Event {
    int hour;
    char *location;
} event_struct;

typedef struct DayAgenda {
    event_struct dayEvents[MAX_EVENTS];
    int numberDayEvents;
} dayAgenda_struct;

/* GLOBAL VARIABLES */
dayAgenda_struct weekEvents[WEEK_EVENTS_LENGTH];

for (int i=0; i< WEEK_EVENTS_LENGTH; i++) {

    dayAgenda_struct das;

    event_struct dayEvents[MAX_EVENTS];

    for (int j=0; j<MAX_EVENTS; j++) {
        event_struct es;
        es.hour = 24;
        // es.location = (char *) malloc(SIZE * sizeof(char));
        es.location = "TEST TEST TEST";
        char *loc;
        scanf( "%[^]%*c", &es.location );


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

return(SUCCESS);
}

