#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256



/* function to find day*/ 

typedef struct agenda {
	int day;
	char event1[SIZE]; //hard coded event size
	char event2[SIZE]; //hard coded event size
	char event3[SIZE]; //hard coded event size
} Agenda;
int main(){
	
{
///have to make a recursion
	printf("Please enter a number for a day\n");
	printf("1) Sunday\n");
	printf("2) Monday\n");
	printf("3) Tuesday\n");
  printf("4) Wednesday\n"); 
 
	int day;
	scanf("%d", &day);
	switch(day){
		case 1:
			printf("you entered Sunday\n");
			break;
		case 2:
			printf("you entered Monday\n");
			break;
    case 3:
      printf("you entered Tuesday");
		default:
			break;
	}
for(int day=0; day<7; day++)
{
  Agenda agendas[7]; //one for each day of the week
				// agendas[0] = Sunday
				// agendas[1] = Monday
    
      char buffer[SIZE];
        char* bufptr = buffer;
        size_t bufsize = SIZE;
        size_t characters;


	for(int i=0; i< 7; i++){
	       	printf("Enter something", agendas[i]);
	       	fflush(stdin);
	       	getline(&bufptr,&bufsize,stdin);
	       	strcpy(agendas[i].event1, buffer);
	       	printf("youe entered %s\n", agendas[i].event1);

	       	printf("have a nice day\n", agendas );
	}

printf("printing all agendas for the week\n");
	for(int i=0; i< 7; i++){
		printf("%s\n", agendas[i].event1);
}

	 

	//print_day(sunday);
	return 0;
}
}
}
