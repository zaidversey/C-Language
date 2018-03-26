/* PROGRAM:  sdt:  Stack Data Type
   AUTHOR:   
   DATE:     24/01/2017
   TOPIC:     
   PURPOSE:  main 
   NOTES:    
             
*/

#include "stack.h"

#define SIZE_A 10

int numRandom(int min, int max );
/**************************************************************************/
/* main( )
 **************************************************************************/
int main( ) {

	stack_t stack  = { NULL, 0, 0 };
	int i, num;
	
	srand( time( NULL ) );
	stack_init(&stack, SIZE_A );
	stack_clear( &stack );
	
	stack_print( stack );
	
	for( i = 0; i < SIZE_A; i++ ) { 
		num = numRandom( 1, 100 );
    		stack_push( &stack, num );
    	}
    	
	stack_print( stack );
	
	return EXIT_SUCCESS;

}

/**************************************************************************/
/* int numRandom(int min, int max );
 **************************************************************************/
int numRandom(int min, int max ) {

	return ( min + rand() % ( max - min + 1 ) );
}



