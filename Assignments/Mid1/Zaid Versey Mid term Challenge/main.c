#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "date.h"

#define OPTIONS "DD MM YY"

extern int daysPerMonth[12];

void display_usage( char *, char * );

/*********************************************************************
 * Main Function
 ********************************************************************/
int main( int argc, char *argv[] ) {

	struct date today;
	struct date next;

	if ( argc != 4 ) {
		display_usage( argv[0], OPTIONS );
		exit( EXIT_FAILURE );
	}	

	/*
	 * Convert arguments into a date
	 */
	today.day   = atoi( argv[1] );
	today.month = atoi( argv[2] );
	today.year  = atoi( argv[3] );

	/*
	 * Find tomorrow's date
	 */

	tomorrow( today, &next );

	/*
	 * Print dates
	 */

	printf("Today is    %d/%d/%d\n", today.day, today.month, today.year);
	printf("Tomorrow is %d/%d/%d\n", next.day, next.month, next.year);


   	return 0; 
} 

/*********************************************************************
 * display_usuage
 ********************************************************************/
void display_usage( char * prog, char *opts ) {

	fprintf(stderr, "usage: %s %s\n", prog, opts );
	return;

}

