/* PROGRAM:  tire.c
   AUTHOR:
   DATE:     22/03/17
   TOPIC:    trie implementation
   PURPOSE:
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "trie.h"

/**************************************************************************/
/* Helper Functions
 * trie_node_t * trie_new(  void );
 *         Allocates memory for a new trie node
 *         Returns NULL if memory allocation was not possible or
 *         a memory address to a trie_node in the heap
**************************************************************************/
trie_node_t * trie_new( void ){

	trie_node_t * tmp = NULL;
	int i;

	if ( ( tmp = ( trie_node_t * ) malloc ( sizeof( trie_node_t ) ) ) == NULL )
		return NULL;

	for( i = 0; i < ALPHA_SIZE; i++ ) {
		tmp->child[ i ] = NULL;
		tmp->end = 1;
	}
	return tmp;
}

/**************************************************************************/
/* Functions functions
 * int trie_size     ( trie_node_t *  root );
 *         Returns the number of words in the trie
 * int trie_contains ( trie_node_t *  root,    char word[ ] );
 *         Returns 1 if a the word is in the trie
 *                 0 otherwise
 * int trie_insert   ( trie_node_t ** rootRef, char word[ ] );
 *         Returns 1 if the word is inserted in the trie
 *                 0 otherwise
 * int trie_remove  ( trie_node_t ** rootRef, char word[ ] );
 *         Returns 1 if the word is removed from the trie
 *                 0 otherwise
 * int trie_destroy  ( trie_node_t ** Tref );
 *         Returns 1 if the trie and all its node are destroyed
 **************************************************************************/
int trie_size ( trie_node_t *  root ) {

    int countWords = 0;
    int i;

    if(root == NULL) return countWords;

    if(root -> end == WORD)
        countWords ++;

    for(i = 0; i < ALPHA_SIZE; i++){
        if(root -> child [i] != NULL){
            countWords += trie_size (root->child [i]);
        }
    }
	return countWords;
}

/**************************************************************************/
int trie_contains ( trie_node_t *  root,    char word[ ] ){
    int i;
    int ind;
    int len = strlen(word);
    /*trie_node_t * crawl = root;*/

    if(root == NULL) return 0;

    for (i=0; i<len; i++){
        if(!isalpha (word[i]) && word[i] != '\'' )
            return 0;
        ind = word [i] == '\'' ? (ALPHA_SIZE - 1): CHAR_TO_INDEX ( word [i] );
        if(!root -> child[ind]) return 0;
        root = root -> child [ind];
    }
    if(root -> end != WORD) return 0;
	return 1;
}
/**************************************************************************/
int trie_insert   ( trie_node_t ** rootRef, char word[ ] ){

    int i, ind;
    int len = strlen(word);
    trie_node_t * crawl = *rootRef;

    if(! * rootRef)
        return 0;

    for (i=0; i<len; i++){
        if(!isalpha(word [i]) && word[i] != '\'')return 0;
        ind = word [i] == '\'' ? (ALPHA_SIZE - 1): CHAR_TO_INDEX ( word [i] );
        if(!crawl -> child [ind]) crawl -> child[ind] = trie_new();
        crawl = crawl -> child[ind];
    }

    if(crawl -> end == WORD)return 0;
    crawl -> end = WORD;
	return 1;
}
/**************************************************************************/
int trie_remove  ( trie_node_t ** rootRef, char word[ ] ){
    int i, ind;
    int len = strlen(word);
    trie_node_t * crawl = *rootRef;

    if(! * rootRef)
        return 0;

    if(trie_contains(crawl, word) == 0)
        return 0;

    for (i=0; i<len; i++){
        if(!isalpha(word [i]) && word[i] != '\'')return 0;
        ind = word [i] == '\'' ? (ALPHA_SIZE - 1): CHAR_TO_INDEX ( word [i] );
        if(!crawl -> child [ind]) return 0;
        crawl = crawl -> child[ind];
    }

    if(crawl -> end == WORD){
    crawl -> end = NO_WORD;
    return 1;
    }
    return 0;


}
/**************************************************************************/
int trie_destroy  ( trie_node_t ** rootRef ){
    trie_node_t *temp = *rootRef;
    int i;

    if (!*rootRef) return 0;

    if (!temp->child) {
        return 0;
    }

    for (i = 0; i < ALPHA_SIZE; i++) {
        if (temp->child != NULL) {
            trie_destroy(&temp->child[i]);
        }
        free(temp->child[i]);
        temp->child[i] = NULL;
    }

    return 1;
}
