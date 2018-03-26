/* PROGRAM:  STACK
   AUTHOR:   
   DATE:     18/01/2017
   TOPIC:     
   PURPOSE:  TEST STACK
   NOTES:    
             
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <check.h>

#include "stack.h"
#include "tests.h"

#define TEST_SUCCESS "SUCCESS: All current tests passed!"
#define TEST_FAILURE "FAILURE: At least one test failed or crashed"
#define FILLER "*****************************************************************************"
#define NUM_RANDOM( min, max ) ( min + (int)( (double)max * rand() / ( RAND_MAX + 1.0 ) ) )


/*******************************************************************/
/* Function Prototypes
 *******************************************************************/
Suite * test_suite(void);
int run_testsuite(void);

/*******************************************************************/
/* main( ) 
 *******************************************************************/
int main(int argc, char* argv[]){

	srand( time( NULL ) );

    	return run_testsuite();
}


/*******************************************************************/
/* test_suit( ) 
 *******************************************************************/
Suite * test_suite(void) {
	Suite *s;
	TCase *tc_stack;
	s = suite_create("ALL CASES");
	tc_stack = tcase_create("STACK");


	/***************  TEST A **********************
	 * Test Cases
	 **********************************************/
   	tcase_add_test(tc_stack, init_NORMAL);
   	
	suite_add_tcase(s, tc_stack);
	
	
	return s;
}

/*******************************************************************/
/* run_testsuite( ) 
 *******************************************************************/
int run_testsuite(){

	int fail_nr;
	Suite *s;
	SRunner *sr;

	printf("%s\n", FILLER );
	
	s = test_suite();
	sr = srunner_create(s);
	
	srunner_run_all(sr, CK_VERBOSE);

	fail_nr = srunner_ntests_failed(sr);
	srunner_free(sr);
	printf("%s\n", FILLER );
	printf("%s\n", fail_nr ? TEST_FAILURE : TEST_SUCCESS );
	printf("%s\n", FILLER );

	return ( !fail_nr ) ? EXIT_SUCCESS : EXIT_FAILURE;
}




