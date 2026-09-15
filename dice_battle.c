/*
Name: Naveed
Course: CSE 1320
Assignment: Dice Battle
Description: A dice game where the player and computer roll until one
             competitor reaches 5 points.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie(void)
{
    return rand() % 6 + 1;
}

void updateScore(int *score, int points)
{
    *score = *score + points;
}

void displayInstructions(void)
{
    printf("================================\n");
    printf("          DICE BATTLE\n");
    printf("================================\n");
    printf("The player and computer each roll one six-sided die.\n");
    printf("The higher roll earns 1 point. A tie earns no points.\n");
    printf("The first competitor to reach 5 points wins the game.\n");
}

int main(void)
{
    int playerScore;
    int computerScore;
    int playerRoll;
    int computerRoll;
    char playAgain = 'y';

    srand(time(NULL));

    do
    {
        playerScore = 0;
        computerScore = 0;

        displayInstructions();

        while (playerScore < 5 && computerScore < 5)
        {
            printf("\nPlayer Score:   %d\n", playerScore);
            printf("Computer Score: %d\n", computerScore);
            printf("\nPress ENTER to roll the dice...");
            getchar();

            playerRoll = rollDie();
            computerRoll = rollDie();

            printf("\n-------------------------------\n");
            printf("Player rolled:   %d\n", playerRoll);
            printf("Computer rolled: %d\n", computerRoll);
            printf("-------------------------------\n");

            if (playerRoll > computerRoll)
            {
                updateScore(&playerScore, 1);
                printf("YOU WIN THE ROUND! +1 POINT\n");
            }
            else if (computerRoll > playerRoll)
            {
                updateScore(&computerScore, 1);
                printf("THE COMPUTER WINS THE ROUND! +1 POINT\n");
            }
            else
            {
                printf("THE ROUND IS A TIE! NO POINTS AWARDED.\n");
            }
        }

        printf("\n================================\n");
        printf("FINAL SCORE\n");
        printf("Player:   %d\n", playerScore);
        printf("Computer: %d\n", computerScore);

        if (playerScore == 5)
        {
            printf("YOU WIN THE DICE BATTLE!\n");
        }
        else
        {
            printf("THE COMPUTER WINS THE DICE BATTLE!\n");
        }
        printf("================================\n");

        /* Bonus enhancement: The player may start a new game. */
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);
        getchar();
        printf("\n");
    }
    while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

/*
Reflection Questions

1. Why does your program need a pointer to modify the score inside your
   function?
   A pointer gives updateScore the address of the original score variable.
   Dereferencing that address with * lets the function change the score in
   main instead of changing only a temporary copy.

2. What does rand() % 6 + 1 accomplish?
   rand() creates a random nonnegative integer. The % 6 operation changes its
   possible result to 0 through 5, and adding 1 shifts that range to 1 through
   6, which matches the faces of a six-sided die.

3. Describe one programming problem you encountered while developing your
   game and how you solved it.
   After scanf reads the play-again letter, the ENTER character remains in the
   input. That could make the next game's first roll happen immediately. I
   added getchar() after scanf to remove that leftover ENTER character.
*/
