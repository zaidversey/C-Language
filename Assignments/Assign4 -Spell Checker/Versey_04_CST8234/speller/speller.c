/* PROGRAM:  speller.c
   AUTHOR:   Zaid versey
   DATE:     01/04/16
   TOPIC:    Spell Checker implementation
   PURPOSE:
   NOTES:

*/
#include "speller.h"

int main ( int argc, char * argv [] ){

    if(argc == 3){

        if(strcmp(argv[1], "-np") != 0){
            perror("wrong option\n");
            exit(-1);
        }
        option_n("dictionary_L.txt", argv[2]);
        option_p("dictionary_L.txt", argv[2]);

    } else if (argc == 4){

        if(strcmp(argv[1], "-p") == 0){
            option_p(argv[2], argv[3]);
        } else if(strcmp(argv[1], "-tp") == 0){
            printf("time taken: %f\n", option_t(argv[2], argv[3]));
            option_p(argv[2], argv[3]);
        } else if(strcmp(argv[1], "-n") == 0){
            option_n(argv[2], argv[3]);
        } else if(strcmp(argv[1], "-t") == 0){
            printf("time taken: %f\n", option_t(argv[2], argv[3]));
        } else {
            perror("Wrong options");
            exit(EXIT_FAILURE);
        }

    } else if (argc == 6){

        if( strcmp(argv[1], "-t") != 0 || strcmp(argv[2], "-p") != 0 || strcmp(argv[3], "-n") != 0 ){
            perror("wrong options\n");
            exit(EXIT_FAILURE);
        }
        printf("time taken: %f", option_t(argv[4], argv[5]));
        option_p(argv[4], argv[5]);
        option_n(argv[4], argv[5]);

    } else {
        perror("arguments");
        exit(EXIT_FAILURE);
    }

    return 0;
}

double calculate (const struct rusage* b , const struct rusage* a){

    if(b == NULL || a == NULL) return 0.0;


    return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec)-
            (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec))+
            ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec)-
            (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
            / 1000000.0);
}
/*
* measures time between loading dictionary, spell chekcing and unloading
*/
double option_t(char *dict_name , char *file_name ){
    struct rusage a;
    struct rusage b;
    FILE* fin;
    char * line = NULL;
    char * word;
    size_t len = 0;
    int misspelled = 0;
    speller dict = NULL;
    dict = trie_new();

    getrusage( RUSAGE_SELF , &a);
    if(load_dictionary(dict_name , dict ) == 0)
        exit(EXIT_FAILURE);


    if((fin = fopen(file_name, "r") ) == NULL){
        perror ("open");
        exit(EXIT_FAILURE);
    }

    if((word=(char*)malloc(45))==NULL){
        perror( "malloc" );
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, fin) != -1){

        word = strtok(line, DELIM );
        while ( word ) {

            if(check_dictionary (dict , word) == 0){
                misspelled++;
            }
            word = strtok(NULL, DELIM);
       }
    }
    fclose (fin);
    unload_dictionary(dict);
    getrusage( RUSAGE_SELF , &b);
    return calculate(&a , &b);
}

/*
* prints linenumber of misspelled word and the misspelled word itself
*/
void option_n(char * dict_name, char * file_name ){

    FILE* fin;
    char * line = NULL;
    char * word;
    size_t len = 0;
    int lineNumber = 0;
    speller dict = NULL;
    dict = trie_new();

    if(load_dictionary(dict_name , dict ) == 0)
        exit(EXIT_FAILURE);

    if(! (fin = fopen(file_name, "r") ) ){
        perror ("open");
        exit(EXIT_FAILURE);
    }

    if((word=(char*)malloc(MAX_WORD))==NULL){
        perror( "malloc" );
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fin)) != -1){

        lineNumber++;
        word = strtok(line, DELIM );
        while ( word ) {
            if(check_dictionary (dict , word) == 0){
                printf("\n");
                printf("line numebr: %d\n", lineNumber);
                printf("misspelled words is: %s\n",word);
            }
            word = strtok(NULL, DELIM);
       }
    }

    fclose (fin);
}

/*
* prints total words in dicitionary, number of misspelled words, and total words in file
*/
void option_p(char * dict_name, char * file_name ){

    FILE* fin;
    char * line = NULL;
    char * word;
    size_t len = 0;
    int misspelled = 0;
    int totalFileWords = 0;
    int totalDictWords = 0;
    speller dict = NULL;
    dict = trie_new();

    if(load_dictionary(dict_name , dict ) == 0)
        exit(EXIT_FAILURE);


    if((fin = fopen(file_name, "r") ) == NULL){
        perror ("open");
        exit(EXIT_FAILURE);
    }

    if((word=(char*)malloc(45))==NULL){
        perror( "malloc" );
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, fin) != -1){


        word = strtok(line, DELIM );
        while ( word ) {

            totalFileWords++;
            if(check_dictionary (dict , word) == 0){
                misspelled++;
            }
            word = strtok(NULL, DELIM);
       }
   }

    fclose (fin);
    totalDictWords = size_dictionary(dict);
    printf("Total words in dictionary: %d\n", totalDictWords);
    printf("Total words in file: %d\n", totalFileWords);
    printf("Total misspelled words in file: %d\n",misspelled);
}
