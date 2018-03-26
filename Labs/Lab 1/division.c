/* PROGRAM:  division.c 
   AUTHOR:   C Ayala 
   DATE:     01/09/16 
   TOPIC:    Division by zero 
   PURPOSE:  run dgb with a program that crashes
   LEVEL OF DIFFICULTY: 0 -- Super Easy
   CHALLENGES:  None
   HOURS:    10 min
*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>

/**************************************************************************/
/* Functions
 **************************************************************************/
int divide( int, int );

/**************************************************************************
 * Main
 **************************************************************************/
int main( void ) {

	int x, y;

	x = 10;
	y = 5;

	printf("%d / %d = %d\n", x, y, divide( x, y ));

	y = 0;
	divide( x, y );
	printf("%d / %d = %d\n", x, y, divide( x, y ));

	return 0;
}

/**************************************************************************
 * Divide two integers
 * No error check
 * returns an integer, loses the decimal part
 **************************************************************************/
int divide( int a, int b ) {

	return a / b;
}
