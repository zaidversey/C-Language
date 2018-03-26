/* FILE:     stack.h
   AUTHOR:
   DATE:     18/01/2017
   TOPIC:
   PURPOSE:  Stack Data Type
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**************************************************************************/
/* Types declarations
 **************************************************************************/
typedef unsigned int data_t;

typedef struct stack {
    data_t *array;
    int size;
    int top;
} stack_t;


#define CLEAR -1

/**************************************************************************/
/* Basic STACK Operations
 *       MUST BE COMPLETED TO PASS THE COURSE
 **************************************************************************/
int    stack_init( stack_t *s, int size );
void   stack_free( stack_t *s );
int    get_stack_size( stack_t s );
int    get_stack_top( stack_t s );
int    get_stack_elements( stack_t s );
int    is_stack_empty( stack_t stack );
int    is_stack_full( stack_t stack );
void   stack_clear( stack_t *s) ;
int   stack_push( stack_t *s, data_t item );
int   stack_pop( stack_t * stack );
int   stack_peek( stack_t  stack);
int    stack_contains( stack_t s, data_t value);
int    stack_find( stack_t s, data_t value);
void   stack_print( stack_t stack );


/**************************************************************************/
/* PART B: COMPARISONS
 **************************************************************************/
int stack_are_equal( stack_t s1, stack_t s2);
int stack_are_disjoint( stack_t s1, stack_t s);

/**************************************************************************/
/* PART C: stack CONSTRUCTORS
 **************************************************************************/
void stack_merge( stack_t *dest, stack_t *s1, stack_t *s2);

#endif
