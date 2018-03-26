/* PROGRAM:  llist.c
   AUTHOR:   C. Ayala
   DATE:     20/10/11
   	         19/03/16
   TOPIC:    simple linked list implementation
   PURPOSE:  Simple data structures
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "llist.h"

/**************************************************************************/
/* Provided functions
 **************************************************************************/

/**************************************************************************/
/* llist_push:  Add an element to the head of the list
 **************************************************************************/
int llist_push( node_t **headRef, int data ) {

	node_t *new;

	if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
		return EXIT_FAILURE;

	new->data = data;
	new->next = *headRef;
	*headRef  = new;

	return 0;

}
/**************************************************************************/
/* llist_pop:   Removes first element of the list
 **************************************************************************/
void llist_pop   ( node_t **headRef ) {

	node_t *h = * headRef;

	if ( h == NULL ) return;

	*headRef = h->next;
	free( h );

	return;
}
/**************************************************************************/
/* llist_size:  Returns number of elements in the list
 **************************************************************************/
int  llist_size  ( node_t * head ) {
	int cnt = 0;

	struct node * tmp = head;

	while( tmp != NULL ) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;

}
/**************************************************************************/
/* llist_print:   Prints a list
 **************************************************************************/
void llist_print ( node_t * head ){

	int nodes = 0;
	struct node *current = head;


	fprintf( stdout, "{ " );
	while( current != NULL ) {
		fprintf( stdout, "%4d -->", current->data );
		nodes++;
		current = current->next;
	}
	fprintf( stdout, " NULL }\n" );

	fprintf(stdout, "Number of elements in the list: %d\n", nodes );

	return;

}

/**************************************************************************/
/* Functions to be implemented by you
 **************************************************************************/
int llist_contains ( node_t *h, int value ) {

    node_t *temp = h;

    while(temp != NULL){
        if(temp->data == value)
            return 1;

        temp = temp->next;
    }
    return 0;
}

int  llist_count    ( node_t *h, int value ) {

    node_t *temp = h;
    int count = 0;

    while(temp != NULL){
        if(temp->data == value)
            count++;

        temp = temp->next;
    }
    return count;
}

int  llist_find     ( node_t *h, int value ) {

    node_t *temp = h;
    int index = 0;

    while(temp != NULL){

        if(temp->data == value)
            return index;

        temp = temp->next;
        index++;
    }
    return -1;
}

int  llist_is_equal ( node_t *h1, node_t *h2 ) {
    node_t *temp1 = h1;
    node_t *temp2 = h2;
    if(llist_size(h1)!=llist_size(h2))
    return 0;

    while(temp1 != NULL){

        if(temp1->data!=temp2->data)
            return 0;
        temp1 = temp1->next;
        temp2 = temp2->next;

    }
    return 1;

}

int llist_addlast  ( node_t **href, int value ) {

    node_t *temp = *href;
    node_t *new;

    if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
        return EXIT_FAILURE;


    if(*href == NULL){
        new->data = value;
        new->next = *href;
        *href  = new;

        return 1;
    }
    while(temp != NULL){

        if(temp->next == NULL){

        	new->data = value;
        	new->next = temp->next;
        	temp->next  = new;

        	return 1;
        }

        temp = temp->next;
    }
    return EXIT_FAILURE;
}

int llist_insert   ( node_t **href, int value , int index ) {
    node_t *curr = *href;
    node_t *prev;
    node_t *new;
    int count = 0;

    if ( ( new = ( node_t *) malloc( sizeof( node_t ) ) ) == NULL )
        return EXIT_FAILURE;


    if(*href == NULL){
        if(index != count)
            return EXIT_FAILURE;

        new->data = value;
        new->next = *href;
        *href  = new;

        return 1;
    }
    while(curr != NULL){

        if(count == index){

        	new->data = value;
        	new->next = curr;
        	prev->next  = new;

        	return 1;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    return EXIT_FAILURE;
}

void llist_remove   ( node_t **href, int value ) {
    node_t *curr = *href;
    node_t *prev;

    if ( *href == NULL ) return;

    if(curr->data == value){
        *href = curr->next;
        free(curr);
        return;
    }

    while(curr != NULL){

        if(curr->data==value) {
            prev->next = curr->next;

            free( curr );
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    return;
}

void llist_free     ( node_t **href ) {

    while(*href!=NULL)
        llist_pop(href);

    return ;
}

void llist_mvnode(node_t **dref, node_t **sref){
    node_t *new = *sref;
    int value;

    if ( *sref == NULL ) return;
    value = new->data;


    llist_push( dref, value );

    llist_pop   ( sref );

}
