#define STACK_A 5

/**********************  INIT TEST **********************************/
/*
 * TEST:  init function:
 *	  ( 1 ) init_NORMAL
 *              stack has been initialized with size > 0
 *              No added elements, top is 0
 *              array should contain a valid address
 *		size should be STACK_A
 *        ( 2 ) init_NOT_NULL
 *              set is NULL
 *              No added elements, size is 0
 * 
 */
 START_TEST ( init_NORMAL ) {
   
    	stack_t stack  = { NULL, 0, 0 };
    	  
    	stack_init(&stack, STACK_A );
    	stack_clear(&stack);
    	ck_assert(get_stack_size(stack) == STACK_A);
    	ck_assert(stack.array != NULL );
    	ck_assert(get_stack_top(stack) == STACK_A);
    	stack_free(&stack);
}
END_TEST
