#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


/* Function: RndGen
 * 
 * Generates a random number, r between 1 and 100.
 * 
 * Returns said random number, r
 */
int RndGen();

/* Function: charPrettyPrint
 * 
 * prints to console a series of characters.
 * 
 * Parameters: l, which represents the length of the series of characters.
 *             c, which represents the character to be printed.
 * Returns void
 */
void charPrettyPrint( char c,int l );

/* Function: gameRun()
 *
 * fallback for recursive function, starts the running of the game. promptgame jumps to this upon exit
 * of recursion.
 * 
 * Returns void
 */
void gameRun();

/* Function: startGame()
 *
 * Constructor function for game variables.
 * 
 * Returns void
 */
void startGame();

/* Function: startGameMenu( char c )
 *
 * Visplay (print) start game text, including rules, and game explanation. 
 * Recursive function thatprompts the user for choice (c) (Y/N)
 * 
 * Returns void
 */
void startGameMenu( char c );

/* Function: promptGame( int r )
 *
 * Resursive function that prompts the user to enter a number for the game, upon which a check to done to determine
 * what to input next.
 * 
 * r is the current value to guess.
 * 
 * exit conditions: game win.
 * 
 * Returns void
 */
void promptGame( int r ); 

/* Function: less( int r )
 *
 * Function for the behavior of the program when the guess is less than the number r
 *  
 * r is the current value to guess.
 * 
 * Returns void
 */
void less( int r );

/* Function: more( int r )
 *
 * Function for the behavior of the program when the guess is more than the number r
 *  
 * r is the current value to guess.
 * 
 * Returns void
 */
void more( int r );

/* Function: won()
 *
 * Function for the behavior of the program when the guess is correct
 * 
 * Returns void
 */
void won();

int main() 
{
    srand(time(0));      // initialisation of srand for rnd() generated, using current time. Must be called once.
    setbuf(stdout, NULL);

    startGame();         //Display Game Screen

    return 0;
}

#pragma region Game Functions
// These functions are utilised in running the game

    void startGame()
    {
        int startcond = -1;
        char choice;
        startGameMenu(choice);
    }

    void startGameMenu( char c ) 
    {
        system("cls") ;          //Clear the console
        charPrettyPrint('-', 120);
        printf("Welcome to the more/less game! \n\n");
        printf("Game instructions ");
        charPrettyPrint(':', 102);
        printf("\nThe game has generated a random number between 1 & 100. Your task is to guess this number.");
        printf("\nUpon taking a guess, you will be told if your guess was more or less than the correct value!");
        printf("\nAre you ready? (Y / N):");
        scanf("%c", &c);

        switch(c) 
        {
            case 'Y':
                gameRun();               //starts game running sequence
                break;

            case 'N':
                system("cls"); 
                printf("Exiting...");   //exits game (returns to startGame)
                break;

            default:
                startGameMenu(c);      //recurses back to startGameMenu.
        }
    }

    void gameRun() 
    {
        int r = RndGen();             // This generates our random number for the game, between 1 and 100.
        system("cls");
        promptGame(r);          
    } 

    void promptGame( int r )
    {
        int userGuess = -1;     // value -1 is used as it is out of bounds for the game
        printf("\nEnter Your Guess: ");
        scanf("%d", &userGuess);

        if (userGuess < 101 && userGuess > 0) 
        {
            if (userGuess > r)
            {
                less(r);
            }
            else if (userGuess < r)
            {
                more(r);
            }
            else 
            {
                won();
            }
        } 
        else 
        {
            printf("Invalid Value! Must be between 1 and 100.. \n"); 
            Sleep(2000);
            promptGame(r);
        }
    }

    void less( int r )
    {
        printf("Less! \n");
        Sleep(600);
        promptGame(r);
    }

    void more( int r )
    {
        printf("More! \n");
        Sleep(600);
        promptGame(r);
    }

    void won() 
    {
        system("cls");
        Sleep(30);
        charPrettyPrint('_', 100);
        printf("You have guessed correctly and have won!");
        Sleep(5000);
    }

#pragma endregion 

#pragma region Utility Functions
// These functions are utilised throughout the code for common calculations and operations

    int RndGen() 
    {
        /* explanation of r = 1 + rand() % 100;
        * Calculation of the value of r to become a random number, where;
        * r = (minimum value) + rand() % (maximum value)
        */
        int r = 1 + rand() % 100;
        return r;
    }

    void charPrettyPrint(char c, int l) 
    {
        for (int i; i < l; i++) 
        {
            printf("%c", c);
        }

        printf("\n");
    }

#pragma endregion

