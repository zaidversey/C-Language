/* PROGRAM:  dictionary.c
   AUTHOR:   Zaid Versey
   DATE:     01/04/16
   TOPIC:    Dictionary implementation
   PURPOSE:
   NOTES:

*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include "dictionary.h"



/**************************************************************************/
/* Dictionary functions
 * int load_dictionary ( const char *dictionay_name, dictionary dict );
 *         Loads dictionary into memory from file dictionary_name
 *         Return the number of words in the dictionary
 *                and dict points to a valid dictionary
 *                0 otherwise and dict points to NULL
 * int check_dictionary ( dictionary dict, const char *word );
 *         Returns 1 if the word is part of the dictionary
 * int size_dictionary ( dictionary dict );
 *         Returns the number of words in the dictionary
 * int unload_dictionary ( dictionary dict );
 *         Unloads dictionary from memory
 *         Returns 1 if successful, 0 otherwise
 **************************************************************************/
int load_dictionary   ( const char *dictionary_name, dictionary dict ){
    FILE* fin;
    char * line = NULL;
    size_t len = 0;
    int length;

    if(! (fin = fopen(dictionary_name, "r") ) ){
        perror ("fopen");
        return 0;
    }

    while (getline(&line, &len, fin) != -1){
        length = strlen(line);
        line[length-1] = '\0'; /*change all \n to \0*/

        if(trie_insert(&dict ,line) == 0){
            dict = NULL;
            return 0;
        }
    }

    fclose (fin);
	return 1;
}
/**************************************************************************/
int check_dictionary  ( dictionary dict, char *word ) {
    int i ,len = strlen(word);
    for(i =0 ; i<len; i++){
        if(word[i] != '\'')
            word[i] = tolower(word[i]);
    }
    if(trie_contains(dict, word) == 0){
        return 0;
    }else {
	    return 1;
    }
}
/**************************************************************************/
int size_dictionary   ( dictionary dict ) {

    int size = trie_size(dict);

	return size;
}
/**************************************************************************/
int unload_dictionary ( dictionary dict ) {

    int destroy = trie_destroy(&dict);

	return destroy;
}
