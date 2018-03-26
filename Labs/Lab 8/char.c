#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int justChars(const char *str, char *nstr);

int main (int argc, char *argv []){

    char *nstr = NULL;
    int length;

    if(argc != 2){
        fprintf(stderr, "Error, number of arguments are %d, 2 arguments are needed \n", argc);
        return EXIT_FAILURE;
    }

    nstr = ((char *) malloc(sizeof(char)*strlen(argv[1]) + 1));

    length = justChars (argv[1], nstr);

    printf("The length of array is: %d %s \n", length, nstr);
    printf("Memory Position of &ostr: %p \n", argv[1]);
    printf("Memory Position of &nstr: %p \n", nstr);
    return 0;
}

int justChars(const char *str, char *nstr){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(isalpha(str[i])){
            nstr[strlen(nstr)] = str[i];
        }
    }

    nstr [strlen(nstr)] = '\0';
    return strlen(nstr);
}
