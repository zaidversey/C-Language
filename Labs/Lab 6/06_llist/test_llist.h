/***************************************************************************/
/*
 * TEST:
 */

START_TEST ( test_mvmove_01 ) {

    node_t * h1 = NULL;
    node_t * h2 = NULL;

    llist_mvnode( &h2, &h1);
    ck_assert( llist_size( h1 ) == 0 );
    ck_assert( llist_size( h2 ) == 0 );
}
END_TEST

START_TEST ( test_mvmove_02 ) {

    node_t * h1 = NULL;
    node_t * h2 = NULL;


    llist_push( &h1, 15  );
    llist_mvnode( &h2, &h1);

    ck_assert( llist_size( h1 ) == 0 );
    ck_assert( llist_size( h2 ) == 1 );
    ck_assert(  llist_contains( h2, 15) );

}
END_TEST

START_TEST ( test_mvmove_03 ) {

   	node_t * h1 = NULL;
   	node_t * h2 = NULL;

    llist_push( &h1, 15  );
    llist_push( &h1, 10 );
    llist_push( &h1, 5  );

    llist_push( &h2, 40 );
    llist_push( &h2, 30 );
    llist_push( &h2, 20 );

    llist_mvnode( &h2, &h1);
    ck_assert( llist_size( h1 ) == 2 );
    ck_assert( llist_size( h2 ) == 4 );

    ck_assert( !llist_contains( h1,  5) );
    ck_assert(  llist_contains( h2,  5) );

}
END_TEST
