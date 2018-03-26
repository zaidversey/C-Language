#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int reverse( char *str );

int main(int argc, char *argv[]){

    if (argc != 2){
        exit(EXIT_FAILURE);
    }

    if(reverse(argv[1]) != 0)
        exit(EXIT_FAILURE);

    printf("%s \n", argv[1]);
    return 0;

}

int reverse( char *str ){
    char temp;
    int i = 0;
    int j = strlen (str) - 1;
    if(j == (-1))
        return EXIT_FAILURE;

    while(i<j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return 0;
}
