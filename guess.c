#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For rand() and srand()
#include <time.h>       // For time() to seed the random number generator

#define MAX_GUESSES 10  // Maximum number of guesses allowed

int main()
{
    char playAgain = 'Y';     // Variable to control the replay loop
    int bestScore = 999;      // Initialize best score with a high value

    srand(time(0));           // Seed the random number generator

    // Main game loop: continues while user wants to play again
    while (playAgain == 'y' || playAgain == 'Y')
    {
        int randomNumber = (rand() % 100) + 1;  // Generate a random number between 1 and 100
        int no_of_guess = 0;                    // Number of attempts made
        int guesse = 0;                         // User's current guess
        int guessedCorrectly = 0;               // Flag to track if guess was correct

        printf("The game has started!\nYou have maximum of %d tries\n", MAX_GUESSES);

        // Loop until the user guesses correctly or exhausts all tries
        while (guesse != randomNumber && no_of_guess < MAX_GUESSES)
        {
            printf("Guess the random number between 1 and 100: ");
            scanf("%d", &guesse);  // Read user input

            if (guesse == randomNumber)
            {
                printf("Your guess is correct!\n");
                guessedCorrectly = 1;  // Set flag to indicate success
                break;                 // Exit the loop
            }
            else if (guesse > randomNumber)
            {
                printf("Too high! Try a lower number.\n");
            }
            else
            {
                printf("Too low! Try a higher number.\n");
            }

            no_of_guess++;  // Increment attempt count
        }

        // Post-game message
        if (guessedCorrectly)
        {
            printf("You guessed the number %d in %d %s.\n", guesse, no_of_guess + 1,
                   (no_of_guess + 1) == 1 ? "try" : "tries");

            // Update best score if this round was better
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
            if (bestScore == 999)
            {
                printf("No best score yet. Try again!\n");
            }
            else
            {
                printf("Your best score so far: %d tries.\n", bestScore);
            }
        }

        // Ask the user if they want to play again
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);  // The space before %c helps to consume any leftover newline
    }

    printf("Thanks for playing\n");
    return 0;
}
