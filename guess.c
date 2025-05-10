#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_GUESSES 10

int main()
{
    char playAgain = 'Y';
    int bestScore=999;
    srand(time(0));
    while (playAgain == 'y' || playAgain == 'Y')
    {
        

        
        int randomNumber = (rand() % 100) + 1;
        int no_of_guess = 0;
        int guesse = 0;
        int guessedCorrectly =0;
        
        printf("The game has started!\nYou have maximum of %d tries\n", MAX_GUESSES);
        while (guesse != randomNumber&&no_of_guess<MAX_GUESSES)
        {
            printf("Guess the random number between 1 and 100: ");
            scanf("%d", &guesse);
            if (guesse == randomNumber)
            {
                printf("Your guess is correct!\n");
                guessedCorrectly=1;
                break;
            }
            else if (guesse > randomNumber)
            {
                printf("Too high! Try a lower number.\n");
            }
            else
            {
                printf("Too low! Try a higher number.\n");
            }
            no_of_guess++;
        }
        if (guessedCorrectly)
        {
            printf("You guessed the number %d in %d %s.\n", guesse, no_of_guess + 1, (no_of_guess + 1) == 1 ? "try" : "tries");
            if (no_of_guess + 1 < bestScore)
            {
                bestScore = no_of_guess + 1;
                printf("New best score!\n");
            }
            printf("Your best score so far: %d tries.\n", bestScore);
        }
        else
        {
            printf("You've used all %d tries! The correct number was %d.\n", MAX_GUESSES, randomNumber);
            if (bestScore == 999){
                printf("No best score yet. Try again!\n");
            }
            else{
                printf("Your best score so far: %d tries.\n", bestScore);
            }
        }
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
    }
    printf("Thanks for playing\n");
    return 0;
}
