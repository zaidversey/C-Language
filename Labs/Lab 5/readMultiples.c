/* PROGRAM:  readMultiples.c 
   AUTHOR:   C. Ayala
   DATE:     15/01/2016
   TOPIC:    C Functions 
   PURPOSE:  Reading from keyboard until EOF ( CTL-D )
   NOTES:    
             
*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define DIGITS 4

/**************************************************************************/
/* Function prototype
 **************************************************************************/
int intData( int d );

/**************************************************************************
 * Main
 * Read numbers until user enter CTL-D or EOF
 **************************************************************************/
int main( void ) {

	int num, i = 0;
	int val;

	printHeader( '-', 80 );
	printf("\n");
	printf("Enter numbers follow by [ ENTER ]\nTo finish enter CTL-D\n");
	
	while ( ( val = fscanf( stdin, "%d", &num )) != EOF ) 
		fprintf( stdout, "READ %d number %06d\n", i++, num );
	
	printf("\n");
	printHeader( '-', 80 );
	fprintf(stdout, "\nRead %5d numbers\n", i );

	return EXIT_SUCCESS;
}
/**************************************************************************
 * printHeader
 **************************************************************************/
void printHeader( char c, int w ) {

	int i;
	
	for ( i = 0; i < w; i ++ )
		printf("%c", c );

}

