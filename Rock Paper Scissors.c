#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


enum rpc  {Rock, Paper, Scissors};

int randomly()
{
	srand(time(0));
	int x = rand() % 3;
	return x;
}

int winner(char you[20])
{
	char r[20] = "Rock";
	char p[20] = "Paper";
	char s[20] = "Scissors";
	int m = randomly();
	
	if ((strcmp(you, "Rock") == 0 || strcmp(you, "rock") == 0) && m == 0)
	{
		printf("PC : %s\n\n", r);
		return 0;
	}
	else if ((strcmp(you, "Rock") == 0 || strcmp(you, "rock") == 0)  && m == 1) //PC
	{
	    printf("PC : %s\n\n", p);
		return 1;
	}
	else if ((strcmp(you, "Rock") == 0 || strcmp(you, "rock") == 0) && m == 2) //you
	{
		printf("PC : %s\n\n", s);
		return 2;
	}
	
	else if ((strcmp(you, "Paper") == 0 || strcmp(you, "paper") == 0) && m == 0) //you
	{
		printf("PC : %s\n\n", r);
		return 3;
	}
	else if ((strcmp(you, "Paper") == 0 || strcmp(you, "paper") == 0) && m == 1) 
	{
		printf("PC : %s\n\n", p);
		return 4;
	}
	else if ((strcmp(you, "Paper") == 0 || strcmp(you, "paper") == 0) && m == 2) // pc
	{
	    printf("PC : %s\n\n", s);
		return 5;
	}
	
	else if ((strcmp(you, "Scissors") == 0 || strcmp(you, "scissors") == 0)  && m == 0) // pc
	{
		printf("PC : %s\n\n", r);
		return 6;
	}
	else if ((strcmp(you, "Scissors") == 0 || strcmp(you, "scissors") == 0) && m == 1) // you
	{
		printf("PC : %s\n\n", p);
		return 7;
	}
	else if ((strcmp(you, "Scissors") == 0 || strcmp(you, "scissors") == 0) && m == 2) 
	{
		printf("PC : %s\n\n", s);
		return 8;
	}
}

void game()
{
	printf("Welcome to the Rock Paper Scissors game!\nYou are against the PC!\n");
	
    int yourScore = 0;
	int PCscore = 0;
	
	for (;(yourScore != 3) && (PCscore != 3);)
	{
	    printf("Select one!\n\nYou:");
	
        char you[100];
        scanf("%s", you);
        int a = winner(you);
		if( a == 0 || a == 4 || a == 8)
		{
		printf("DRAW!\n\nYou : %d PC : %d\n\n\n", yourScore, PCscore);
		}
		
		if(a == 1  || a == 5 || a == 6)
		{
		PCscore = PCscore + 1;	
		printf("PC got the score\n\nYou : %d PC : %d\n\n", yourScore, PCscore);
		}
		
		if(a == 2 || a == 3 || a == 7)
		{
		yourScore = yourScore + 1;	
		printf("You got the score\n\nYou : %d PC : %d\n\n", yourScore, PCscore);
		}			
	}
	
	if (PCscore > yourScore)
	printf("You lost! Maybe next time!\n");
	else if(PCscore < yourScore)
	printf("You won! Congratulations\n");
}

void main()
{
	int a;
   do
   {
   	game();
   	printf("Do you want to continue? (Y:1 N:0)\n");
   	scanf("%d", &a);
   	printf("\n\n");
   } while(a == 1);
   
   system("pause");		
}

