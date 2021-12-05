/*
 * agenda.c
 */
#include "agenda.h"

/* GLOBAL VARIABLES */

/* FUNCTIONS */

/* function to find day*/ 
int getIntegerOfDay(char *day) {
	if( strcmp(day, "sunday") == 0 ) return 0;
	if( strcmp(day, "monday") == 0 ) return 1;
	if( strcmp(day, "tuesday") == 0 ) return 2;
	if( strcmp(day, "wednesday") == 0 ) return 3;
	if( strcmp(day, "thursday") == 0 ) return 4;
	if( strcmp(day, "friday") == 0 ) return 5;
	if( strcmp(day, "saturday") == 0 ) return 6;
	else return -1;
}

void printDay(int dayInt) {
	if( dayInt==0 ) printf("Sunday \n --------\n");
	if( dayInt==1 ) printf("Monday \n --------\n");
	if( dayInt==2 ) printf("Tuesday \n --------\n");
	if( dayInt==3 ) printf("Wednesday \n --------\n");
	if( dayInt==4 ) printf("Thursday \n --------\n");
	if( dayInt==5 ) printf("Friday \n --------\n");
	if( dayInt==6 ) printf("Saturday \n --------\n");

}
void printEvent(event name) {
	printf("Time:%s\nDate:%s\nLocation:%s\nDescription:%s\n", name.time, name.date, name.location, name.description);
	printf("This works");
}

int runAgendaMaker(void) {
	 dailyAgenda Agendas[7]; // each index here is day of week (0 is sunday)/
        int forever = 1;

        // Initialize the numOfEvents to make sure its set to 0/
        // so ervetythign else works/
        for(int i = 0; i<7; i++) {
                Agendas[i].numOfEvents = 0;
        }          
	printf("Welcome to Agenda Maker,/n press 1 create event,/n 2 view event,\n  press 3 to exit.");
	int selection;
	
	scanf("%d", &selection);
	char day[20];
	
	switch (selection){
		case 1:
		case 2: 
			printf("What day are you interested in. \n");
			scanf("%s", day);
			break;
		case 3:
			return 0;
		
	}
	printf("got here");
	int currentday = getIntegerOfDay(day);
	dailyAgenda currentAgenda = Agendas[currentday]; 
	printf("Press 1 to add event,\n 2 to view events,\n 3 to delete event.\n");
	switch (selection){
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
			scanf("%s", location);
			printf("Description:\n");
			scanf("%[^\n]%*c", description);
			}
			break;
 
		 case 2:
			
			for(int i=0; i<currentAgenda.numOfEvents; i++) {
				printEvent(currentAgenda.arrayEvent[i]);
			} 
	}
	       
		
			 
			
	
	/*dailyAgenda Agendas[7]; // each index here is day of week (0 is sunday)/
	int forever = 1;

	// Initialize the numOfEvents to make sure its set to 0/
	// so ervetythign else works/
	//for(int i = 0; i<7; i++) {
	//	Agendas[i].numOfEvents = 0;
	//}

	//while(forever) {
		printf("\e[0;33m \n> \e[0;37m");
		char *userInput = (char *) malloc(SIZE * sizeof(char));
		char *token
		const char *s = " ";
		char *name = malloc(SIZE * sizeof(char));

        scanf("%[^\n]%*c", userInput);
		
		token = (char *) strtok(userInput, s);
        while (token != NULL) {



		* get the first token */

		/* strcmp returns 0 if the two inputs are a match */

        /* HELP */
        /* CMD)monday]buy food */
	/*	if( strcmp(token, "help") == 0 ) {
 			printf("add [day] [event] , Add event to day\n");
			printf("show [day/'all'] , show all the events for selected day, or for 'all'");
			printf("edit [day] [eventNumber] [task], edit a day's event indexed by eventNumber "); 	
	    }

       */ /* ADD *//*
	    if( strcmp(token, "add") == 0 ) {
	    	char *day = strtok(NULL, s); // grab second arg
	    	char *task = strtok(NULL, s); // grab 3rd arg (but its a single word, woops)
    		int dayInt = getIntegerOfDay(day); // encodes our day to a number, use for indexing
		
    		if(dayInt == -1){
    			printf("\n Entered invalid day");
    			continue;
            }

    	    // This day has numOfEvents events
    	    int numOfEvents = Agendas[dayInt].numOfEvents;
	
    	    if (numOfEvents > 9){ 
    	    	printf("Too many events on day %s", day);
    	    	continue;
    	    }

    	    // We want to write our new task to the next open spot, which is index numOfEvents
    	    strcpy(Agendas[dayInt].events[numOfEvents], task);

    	    // Make sure we increase the numOfEvents of this specific day
    	    // so we dont overwrite it when we add another task to this day
    	    Agendas[dayInt].numOfEvents++;
    	    printf("New task: %s\n", Agendas[dayInt].events[numOfEvents]);
        }
    
        *//* SHOW 
	    if( strcmp(token, "show") == 0){
	    	char *day = strtok(NULL, s);
	    	int dayInt = getIntegerOfDay(day); // encodes our day to a number, use for indexing

             ALL */
    	/*	if( strcmp(day, "all") == 0){

    			// Print out every single day and all their events
    			for(int i=0; i<7; i++){ // Day loop
    				printDay(i);
    				for(int j=0; j < Agendas[i].numOfEvents; j++){ // Event loop
    					printf("%d : %s\n", j+1, Agendas[i].events[j] );
    				}
    				printf("\n");
    			}
    			continue;
    		}	

    		if(dayInt == -1){
    			printf("\n Entered invalid day");
    			continue;
    		}

    		// print the events for this day
    		for( int i = 0; i < Agendas[dayInt].numOfEvents; i++){
    			printf("%s\n", Agendas[dayInt].events[i] );
    		}	
        }
    token = strtok(NULL, s);
    }
	}
*/
}
