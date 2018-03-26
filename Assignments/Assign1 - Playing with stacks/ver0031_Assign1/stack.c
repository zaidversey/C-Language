/* FILE:     stack.c
   AUTHOR:
   DATE:     18/01/2017
   TOPIC:
   PURPOSE:  Basic Stack data type function implementations
   NOTES:

*/

#include "stack.h"


/**************************** PART A***************************************/



int    stack_contains( stack_t s, data_t value);
int    stack_find( stack_t s, data_t value);
void   stack_print( stack_t stack );


/**************************************************************************/
/* stack_int
 *        Initializes a new set
 *        O( 1 ) operation
 *   PRE:
 *        There is enough memory allocated for set
 *   To DO:
 *        ( 1 ) Allocate memory for an array of size elements
 *              -- Don't forget to check if memory is available
 *        ( 2 ) Set size to size
 *        ( 3 ) Set top to size ( last posititon )
 *   RETURN
 *        0 if init was OK
 *       -1 if init encountered an error ( only problem is memory allocation)
 **************************************************************************/
int    stack_init( stack_t *stack, int size ) {

	if ( stack->array ) return -1;

	if ( !( stack->array = ( data_t * ) malloc ( sizeof( int ) * size )))
		return EXIT_FAILURE;

	stack->size = size;
	stack->top = size;

	return 0;
}
/**************************************************************************/
/* stack_free
 *        Deallocates memory associated with a stack
 *        It must set top and size to zero
 **************************************************************************/
void stack_free( stack_t *stack ){
    if(stack->array == NULL){
        printf("This will cause a segmentation fault, please try again");
    }else{
    /*free(stack);*/
    /*stack->array=NULL;*/
    free(stack->array);
    stack->top=0;
    stack->size = 0;
    }
}
/**************************************************************************/
/* get_stack_size
 *        Returns the size of the stack
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_size( stack_t stack ) {
    return stack.size;
}
/**************************************************************************/
/* get_stack_top
 *        Returns position of the top
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_top( stack_t stack ) {
    return stack.top;
}
/**************************************************************************/
/* get_stack_elements
 *        Returns the numbers of items in the stack
 *        O( 1 ) operation
 **************************************************************************/
int get_stack_elements( stack_t stack ) {
    return (stack.size - stack.top);
}
/**************************************************************************/
/* is_stack_empty
 *        returns 1 if stack is empty, 0 otherwise
 *        stack is empty when top is size
 *
 **************************************************************************/
int    is_stack_empty( stack_t stack ){
    if(stack.top == stack.size){
        return 1;
    }else {
        return 0;
    }
}
/**************************************************************************/
/* is_stack_full
 *        returns 1 if stack is full, 0 otherwise
 *        stack is full when top is zero
 *
 **************************************************************************/
int    is_stack_full( stack_t stack ){
    if(stack.top == 0){
        return 1;
    }else {
        return 0;
    }
}
/**************************************************************************/
/* stack_clear
 *        Removes all elements from a set (doesn't deallocate anything!).
 *        clear elements with value CLEAR
 *        top is set to last index ( size - 1 )
 *        This function could be called to initialize all elements to
 *        the CLEAR value or to ERASE all the array information
 **************************************************************************/
void stack_clear( stack_t *stack){
    int i;
    if(stack->array==NULL) {
        printf("\nStack not intialized, try again\n");
    }else if(stack->top >= stack->size){
        printf("\nStack is empty, nothing to clear, try again\n");
    }else if((stack->top<0)){
        printf("\nTop is a negative, Something went wrong, try again\n");
    }else {
        for(i = 0; i<stack->size; i++){
            stack->array[i] = CLEAR;
        }
        stack->top=stack->size;
    }
}
/**************************************************************************/
/* stack_push
 *        Adds an item to a stack ( always on the top )
 *
 **************************************************************************/
int stack_push( stack_t *stack, data_t value ){
    if((stack->array == NULL) || (value < 0) || (stack->top <= 0)){
        return 0;
    }else {
        stack->top --;
        stack->array[stack->top]=value;
        return 1;
    }
}
/**************************************************************************/
/* stack_pop
 *        removes an item to a stack ( always on the top )
 *
 **************************************************************************/
int stack_pop( stack_t *stack ){
    if(stack->array==NULL) {
        printf("\nStack not intialized, try again\n");
        return EXIT_FAILURE;
    }else if(stack->top >= stack->size){
        printf("\nStack is empty, nothing to clear, try again\n");
        return EXIT_FAILURE;
    }else if((stack->top<0)){
        printf("\nTop is a negative, Something went wrong, try again\n");
        return EXIT_FAILURE;
    }else {
        printf("\nItem popped was: %d \n", stack->array[stack->top]);
        stack->array[stack->top]=CLEAR;
        stack->top ++;
        return(stack->array[stack->top]);
    }
}
/**************************************************************************/
/* stack_peek
 *        shows the item on the top of the stack
 *
 **************************************************************************/
int stack_peek( stack_t stack ){
    if(stack.array==NULL) {
        printf("\nStack not intialized, try again\n");
        return EXIT_FAILURE;
    }else if(stack.top >= stack.size){
        printf("\nStack is empty, nothing to clear, try again\n");
        return EXIT_FAILURE;
    }else if((stack.top<0)){
        printf("\nTop is a negative, Something went wrong, try again\n");
        return EXIT_FAILURE;
    }else {
        return (stack.array[stack.top]);
    }
}
 /**************************************************************************/
/* stack_contains
 *        Returns true of value is a member of the stack
 *        It does not return the index where value is!
 * RETURN
 *        1 if the element is a member of the set
 *        0 otherwise
 **************************************************************************/
 int stack_contains( stack_t stack, data_t value){
     int i;
     if(stack.array==NULL) {
         printf("\nStack not intialized, try again\n");
         return EXIT_FAILURE;
     }else if(stack.top >= stack.size){
         printf("\nStack is empty, nothing to clear, try again\n");
         return EXIT_FAILURE;
     }else if((stack.top<0)){
         printf("\nTop is a negative, Something went wrong, try again\n");
         return EXIT_FAILURE;
     }else if(value < 0){
         return EXIT_FAILURE;
     }else {
         for (i=stack.size -1; i>=stack.top; i--){
             if(stack.array[i]==value){
                 return 1;
             }
         }
    }
    return 0;
}
/**************************************************************************/
/* stack_find
 *        Returns the index where value is
 * RETURN
 *        index where the element is in the set
 *        -1 if not found
 **************************************************************************/
 int stack_find( stack_t stack, data_t value){
     int i;
     if(stack.array==NULL) {
         printf("\nStack not intialized, try again\n");
         return EXIT_FAILURE;
     }else if(stack.top >= stack.size){
         printf("\nStack is empty, nothing to clear, try again\n");
         return EXIT_FAILURE;
     }else if((stack.top<0)){
         printf("\nTop is a negative, Something went wrong, try again\n");
         return EXIT_FAILURE;
     }else if(value < 0){
         return EXIT_FAILURE;
     }else {
         for (i=stack.size -1; i>=stack.top; i--){
             if(stack.array[i]==value){
                 return i;
             }
         }
    }
    return EXIT_FAILURE;
 }

/**************************************************************************/
/* stack_print
 *        prints the stack and its elements
 **************************************************************************/
void   stack_print( stack_t stack ) {
    int i;
    if(stack.array==NULL) {
        printf("\nStack not intialized, try again\n");
        return;
    }else if(stack.top >= stack.size){
        printf("\nStack is empty, nothing to clear, try again\n");
        return;
    }else if((stack.top<0)){
        printf("\nTop is a negative, Something went wrong, try again\n");
        return;
    }else {
        for (i=0; i<stack.size; i++){
            printf("%d ", stack.array[i]);
        }
        printf("\n");
    }
}

/*************************PART B***************************************/

/**********************************************************************/
/* stack_are_equal
 *        Returns true if and only if stack1 is equal to stack2.
 *        Two stacks are equal if they have the same number of elements
 *        and all elements are in the same position
 **********************************************************************/
int stack_are_equal( stack_t s1, stack_t s2){
    int i,j;
    if((s1.array == NULL && s2.array == NULL) || (s1.top==s1.size && s2.top==s2.size)){
        return 1;
    if(get_stack_elements(s1) != get_stack_elements(s2))
        return 0;

    for (i=s1.top, j=s2.top; i<s1.size; i++, j++)
            if(s1.array[i] != s2.array[j])
                return 0;
    return 1;
}
/*********************************************************************/
/* stack_are_disjoint
 *        Returns true if and only if stack1 and stack2 don't contain any
 *        of the same items
 *********************************************************************/
int stack_are_disjoint( stack_t s1, stack_t s2){
    if(stack_are_equal(s1, s2) == 1){
        return 0;
    }else {
        return 1;
        /*
        for (i=s1.top; i<s1.size; i++){
            for(j=s2.top; j<s2.size; j++){
                if(s1.array[i] == s2.array[j]){
                    continue;
                }else {
                    return 1;
                }
            }
        }
        printf("two");
        return 0;
        */
    }
}

/*************************PART C***************************************/
/*********************************************************************/
/* stack_merger
 *        merges stack1 and stack2, storing it in dest.
 *        stack1 and stack2 are freed
 *********************************************************************/
void stack_merge( stack_t *dest, stack_t *s1, stack_t *s2){
    if(s1->array == NULL || s2->array == NULL ||
s1->top == s1->size || s2->top == s2->size){
        return;
    }else{
        int i;
        int j;

        dest->size = (s1->size) + (s2->size);
        stack_init(dest, dest->size);

        /*push first from stack 2*/
        for(i = s2->size -1; i>= s2->top; i--){
            stack_push(dest,s2->array[i]);
        }
        /*then push from stack 1*/
        for(j = s1->size -1; j>= s1->top; j--){
            stack_push(dest,s1->array[j]);
        }

        stack_free(s1);
        stack_free(s2);
    }
}
