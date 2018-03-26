/* PROGRAM:  DATE
   AUTHOR:   
   DATE:     16/02/2017
   TOPIC:     
   PURPOSE:  TEST DATE
   NOTES:    
             
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <check.h>

#include "date.h"
#include "dates.h"

#define TEST_SUCCESS "SUCCESS: All current tests passed!"
#define TEST_FAILURE "FAILURE: At least one test failed or crashed"
#define FILLER "*****************************************************************************"

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
	TCase *tc_t;

	s = suite_create("ALL CASES");
	tc_t = tcase_create("DATE TEST");


	/*TESTING:  tomorrow */
   	tcase_add_test(tc_t, tomorrow_DAY);
   	tcase_add_test(tc_t, tomorrow_MONTH);
   	tcase_add_test(tc_t, tomorrow_YEAR);
   	tcase_add_test(tc_t, tomorrow_LEAP_BEFORE);
   	tcase_add_test(tc_t, tomorrow_LEAP_AFTER);



	suite_add_tcase(s, tc_t);


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




