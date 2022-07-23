#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/* enum: diff
 *
 * Each value is an integer to determine the number of tries. -1 is used to represent unlimited tries
 */
typedef enum
{
    easy = -1,
    medium = 25,
    hard = 10
} diff_enum; diff_enum tries;

/* Function: RndGen
 * 
 * Generates a random number, r between 1 and 100
 * 
 * Returns said random number, r
 */
int RndGen();

/* Function: charPrettyPrint
 * 
 * prints to console a series of characters
 * 
 * Parameters: 
 * l, which represents the length of the series of characters,
 * c, which represents the character to be printed
 * 
 * Returns void
 */
void charPrettyPrint( char c, int l );

/* Function: startGame()
 *
 * Constructor function for game variables
 * 
 * Returns void
 */
void startGame();

/* Function: gameDiff()
 *
 * Recursive game difficulty menu, after the choice, the player is sent to the startGame function
 * 
 * Returns void
 */
void gameDiff();

/* Function: startGameMenu( char c )
 *
 * Visplay (print) start game text, including rules, and game explanation. 
 * Recursive function thatprompts the user for choice (c) (Y/N)
 * 
 * Returns void
 */
void startGameMenu( char c );

/* Function: gameRun( diff_enum tries )
 *
 * fallback for recursive function, goes to the game difficulty menu. promptgame jumps to this upon exit
 * of recursion
 * 
 * tries represents the difficulty enum
 * 
 * Returns void
 */
void gameRun( diff_enum tries );

/* Function: promptGame( int r, int t )
 *
 * Resursive function that prompts the user to enter a number for the game, upon which a check to done to determine
 * what to input next
 * 
 * Parameters: 
 * r, which is the current random number to guess,
 * t, which is the number of tries left 
 * 
 * Exit conditions: 
 * a) game win,
 * b) out of tries
 * 
 * Returns void
 */
void promptGame( int r, int t ); 

/* Function: less( int r, int t  )
 *
 * Function for the behavior of the program when the guess is less than the number r
 *  
 * Parameters: 
 * r, which is the current random number to guess,
 * t, which is the number of tries left 
 * 
 * Returns void
 */
void less( int r , int t);

/* Function: more( int r, int t  )
 *
 * Function for the behavior of the program when the guess is more than the number r
 *  
 * Parameters: 
 * r, which is the current random number to guess,
 * t, which is the number of tries left 
 * 
 * Returns void
 */
void more( int r , int t);

/* Function: checkLost( int t )
 *
 * Check if the user has run out of tries
 * 
 * t represents the number of tries
 * 
 * Returns void
 */
void checkLost(int t);

/* Function: won()
 *
 * Function for the behavior of the program when the guess is correct
 * 
 * Returns void
 */
void won();

/* Function: lost()
 *
 * Function for the behavior of the program when the user has run out of tries
 * 
 * Returns void
 */
void lost();

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
        #pragma region Game Menu Text

            system("cls");          // clear the console
            charPrettyPrint('-', 120);
            printf("Welcome to the more/less game! \n\n");
            printf("Game instructions ");
            charPrettyPrint(':', 102);
            printf("\nThe game has generated a random number between 1 & 100. Your task is to guess this number.");
            printf("\nUpon taking a guess, you will be told if your guess was more or less than the correct value!");
            printf("\nAre you ready? (Y / N):");
            scanf("%c", &c);

        #pragma endregion

        switch(c) 
        {
            case 'Y':
                gameDiff();              // difficulty menu
                break;

            case 'N':
                system("cls"); 
                printf("Exiting...");   // exits game (returns to startGame)
                break;

            default:
                startGameMenu(c);      // recurses back to startGameMenu.
        }
    }

    void gameDiff()
    {
        #pragma region text
            int c;

            system("cls");
            charPrettyPrint('-', 120);
            printf("Please Choose a difficulty: ");
            printf("\n1] Easy: Unlimited Tries");
            printf("\n2] Medium: 25 Tries");
            printf("\n3] Hard: 10 Tries");
            printf("\n: ");

            scanf("%d", &c);
        #pragma endregion

        switch(c)
        {
            case 1:
                gameRun(easy);
                break;
            
            case 2:
                gameRun(medium);
                break;
            
            case 3:
                gameRun(hard);
                break;
            
            default:
                gameDiff();
        }
    }

    void gameRun(  diff_enum tries ) 
    {
        int r = RndGen();             // This generates our random number for the game, between 1 and 100.
        system("cls");
        promptGame(r, tries);          
    } 

    void promptGame( int r, int t )
    {
        int userGuess = -1;     // value -1 is used as it is out of bounds for the game
        printf("Tries: %d", t);
        printf("\nEnter Your Guess: ");
        scanf("%d", &userGuess);

        if (userGuess < 101 && userGuess > 0) 
        {
            if (t == 0) {lost();}

            else if (userGuess > r)
            {
                less( r , t );
            }
            else if (userGuess < r)
            {
                more( r , t );
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
            promptGame(r, t);
        }
    }

    #pragma region Win Loss Conditionals

        void less( int r , int t)
        {
            printf("Less! \n");
            t--;
            Sleep(200);
            promptGame(r, t);
        }

        void more( int r, int t )
        {
            printf("More! \n");
            t--;
            Sleep(200);
            promptGame(r, t);
        }

        void won() 
        {
            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("You have guessed correctly and have won!");
            Sleep(5000);
        }

        void lost() 
        {
            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("You have guessed incorrectly too many times and have lost the game!");
            Sleep(5000);
        }

    #pragma endregion

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

