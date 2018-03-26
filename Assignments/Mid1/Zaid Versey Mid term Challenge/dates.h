#define STACK_A 5
#define STACK_B 10

/**********************  date( ) ********************************/
/*
 * TEST:  tomorrow function
 */
 START_TEST ( tomorrow_DAY ) {
   
    date_t today  = { 1, 2, 1970 };
    date_t next;
    	  
    tomorrow( today, &next);
    ck_assert( next.day   == 2 );
    ck_assert( next.month == 2 );
    ck_assert( next.year  == 1970 );

}
END_TEST

 START_TEST ( tomorrow_MONTH ) {
   
    date_t today  = { 28, 2, 1970 };
    date_t next;
    	  
    tomorrow( today, &next);
    ck_assert( next.day   == 1 );
    ck_assert( next.month == 3 );
    ck_assert( next.year  == 1970 );

}
END_TEST

 START_TEST ( tomorrow_YEAR ) {
   
    date_t today  = { 31, 12, 1992 };
    date_t next;
    	  
    tomorrow( today, &next);
    ck_assert( next.day   == 1 );
    ck_assert( next.month == 1 );
    ck_assert( next.year  == 1993 );

}
END_TEST

 START_TEST ( tomorrow_LEAP_BEFORE ) {
   
    date_t today  = { 28, 2, 1988 };
    date_t next;
    	  
    tomorrow( today, &next);
    ck_assert( next.day   == 29 );
    ck_assert( next.month == 2 );
    ck_assert( next.year  == 1988 );

}
END_TEST

 START_TEST ( tomorrow_LEAP_AFTER ) {
   
    date_t today  = { 29, 2, 1988 };
    date_t next;
    	  
    tomorrow( today, &next);
    ck_assert( next.day   == 1 );
    ck_assert( next.month == 3 );
    ck_assert( next.year  == 1988 );

}
END_TEST
