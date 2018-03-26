/* PROGRAM: reverse.c  
   AUTHOR:  Zaid Versey
   DATE:    Jan 15/17
   PURPOSE: This is a program that:
     	  1. The player rolls the dice and adds up the face values.
	  2. If the first roll is a 7 or 11, the player wins.
	  3. If the first roll is a 2, 3 or 12, the player looses.
	  4. If the first roll is any other number, that sum becomes the player's point.
	  5. To win, the player must continue rolling the dice until he/she “makes point.”
	  6. The player loses by rolling a 7 before the point. 
   LEVEL OF DIFFICULTY: 4
   CHALLENGES: playGame function
   HOURS SPENT: 5             
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WON 0
#define LOSE 1

int rollDice(void);
int playGame(void);

int main (void){

	char playAgain;
	int wins = 0;
	int losses = 0;
	int result;
	bool gameAgain = true;
	
	while(gameAgain){
		printf("\t\t\t\tROLL THE DICE [ENTER]\n");
		printf("------------------------------------------------------------------------------\n");
		printf("%11s\t %11s\t %11s\t %11s\t %11s\n", "ROLL NUM", "DICE #1", "DICE #2", "TOTAL ROLL", "POINT MATCH");
		printf("------------------------------------------------------------------------------\n");
		result = playGame();
	
		if (result == WON) {
            wins++;
		} else if (result == LOSE) {
            losses++;
		}
	
		printf("\nAnother game? [ Y/ N ]");
		scanf("%c", &playAgain);
		
		if (playAgain == 'y' || playAgain == 'Y') {
            gameAgain = true;
        } else if (playAgain == 'n' || playAgain == 'N') {
            printf("Thanks for playing\n");
            printf("You won %d games and lost %d games. \n", wins, losses);
            gameAgain = false;
        }
	}
	
	return EXIT_SUCCESS;
}

int rollDice(void){
	/*
	int max = 1;
	int min = 6;
	
	return ( min + rand() % ( max - min + 1 ) );
	*/
	
    return ((rand() % 6) + 1);

}

int playGame(void){
	int dice1 =0;
	int dice2 =0;
	int totalRoll = 0;
	int rollNum = 1;
	int point = 0;
	int result;
	srand( time( NULL ) );
	bool playToPoint = true;	
	fgetc(stdin);
	dice1 = rollDice();
	dice2 = rollDice();
	totalRoll = dice1 + dice2;
	point = totalRoll;
	printf("%11d\t %11d\t %11d\t %11d\t %11d", rollNum++, dice1, dice2, totalRoll, point);

	if (totalRoll == 7 || totalRoll == 11){
		printf("\nConratulations you roll %d and WON at your first try!!!!", totalRoll);
		result = WON;
		playToPoint = false;
	}else if(totalRoll == 2 || totalRoll == 3 || totalRoll == 12){
		printf("\nSorry you roll %d and you lose on your first try!!!!", totalRoll);
		result = LOSE;
		playToPoint = false;
	}else{
		
		while (playToPoint){
			fgetc(stdin);
			dice1 = rollDice();
			dice2 = rollDice();
			totalRoll = dice1 + dice2;
			printf("%11d\t %11d\t %11d\t %11d\t %11d", rollNum++, dice1, dice2, totalRoll, point);
			
			if(totalRoll == 7){
				printf("\nSorry you roll %d and you lose\n", totalRoll);
				result = LOSE;
				playToPoint = false;
			}else if(totalRoll == point){	
				printf("\nConratulations you roll %d and WON!!!!\n", totalRoll);
				result = WON;
				playToPoint = false;
			}
		}		
	}
	return result;
}



