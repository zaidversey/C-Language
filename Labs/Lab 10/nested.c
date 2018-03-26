/*
*   Author: Vitor de Souza
    Purpose: The soul purpose of this lab is to practice reading args from the cmd.
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  /*include functions like int ispunct(int c) that checks if character is a punctuation .,(){}, etc*/
#include <fcntl.h> /*include library for O_RDONLY, O_WRONLY, etc*/


#define OPTIONS "-t -i"

void display_usage(char *, char*);
int nested(char *);

int main (int argc, char *argv[]){
    FILE *source;
    char *line = NULL; /*each line been read from file*/
    int len = 0;
    int countNest = 0;
    int index = 0;
    int countNotNest = 0;




    if (argc != 3){
        display_usage(argv[0], OPTIONS);
        return EXIT_FAILURE;
    }

    if ( ( source = fopen(argv[2], "r") ) == NULL){
        perror(argv[2]);
        return EXIT_FAILURE;
    }

    if ( !strcmp(argv[1], "t") && !strcmp(argv[1], "i") ){
        printf("Wrong option %s", argv[1]);
        return EXIT_FAILURE;
    }

    while ( (getline(&line, &len, source)) != -1){
        if (nested(line)){
            printf("%d: [OK] %s\n",index, line);
            countNest++;
        }else{
            printf("%d: [NO] %s\n",index, line);
            countNotNest++;
        }
        index++;
    }

    /*if (strcmp(argv[1], "t")){
        int j = 0;
        while (j<countNest){
            printf("%d: [OK] %s\n",j, line);
        }

    }
    */


    fclose(source);
    return 0;



}

void display_usage(char *prog, char* args){
    fprintf(stderr, "Usage: Wrong num of arguments, has to be %s %s\n",prog, args);
    return;
}

int nested(char *str){
    int i = 0;
    int j = 0;
    int openPunct = 0;
    int closePunct = 0;

    if (str == NULL || !ispunct(atoi(str)) == '(' || !ispunct(atoi(str)) == ')' ){
        return 1; /*if string is empty, or does not contain any punctuation it is nested*/
    }

    for (i = 0, j =strlen(str)-1 ; i<=j; i++, j--){ /*or str[i] != '\0'*/
        if (ispunct(str[i]) == '('){
            openPunct++;
        }

        if(ispunct(str[j]) == ')'){
            closePunct++;
        }
    }

    if (openPunct == closePunct || isalpha(str)){
        return 1;
    }

    return 0;

}
