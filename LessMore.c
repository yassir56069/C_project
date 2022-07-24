#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#pragma region Function And Enum Prototypes

    #pragma region Enums

        /* enum: diff{}
        *
        * Each value is an integer to determine the number of tries. -1 is used to represent unlimited tries
        */
        typedef enum
        {
            easy = -1,
            medium = 25,
            hard = 10
        } diff_enum; diff_enum tries;

    #pragma endregion

    #pragma region Utility Functions

        /* Function: RndGen()
        * 
        * generates a random number, r between 1 and 100
        * 
        * Returns said random number, r
        */
        int RndGen();

        /* Function: charPrettyPrint( char c, int l )
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

    #pragma endregion

    #pragma region Game Functions

        /* Function: startGame()
        *
        * constructor function for game variables
        * 
        * Returns void
        */
        void startGame();

        /* Function: startGameMenu( char c )
        *
        * display (print) start game text, including rules, and game explanation. 
        * Recursive function that prompts the user for choice (c) (Y/N)
        * 
        * Returns void
        */
        void startGameMenu( char c );

        /* Function: SorM()
        *
        * recursive menu to choose between 1 or 2 player mode
        * 
        * Returns void
        */
        void SorM( char c );

        #pragma region Multiplayer Functions

            /* Function: MPInit()
            *
            * initialises and constructs Multi-Player game variables and functions
            * 
            * Returns void
            */
            void MPInit();

            /* Function: MPTries( int iter )
            *
            * takes user input for number of tries, then jumps into gameRunMP. The function determines the winner then sends to winnerMP for printing
            * 
            * iter is the current iteration in MPTries loop. this is used to determine which player should be deciding the number of rounds currently.
            * 
            * Returns void
            */
            int MPTries( int iter );

            /* Function: MPRounds()
            *
            * takes user input for number of rounds, then jumps into gameRunMP
            * 
            * Returns number of rounds
            */
            int MPRounds();

            /* Function: gameRunMP( int tries, int player )
            *
            * launches promptGame. takes tries values from promptGame, calculates them into score and stores them in array "scores".
            * 
            * Parameters: 
            * tries, which is the number of tries the player has for that round 
            * player, which is the current player (1 or 2)
            * 
            * this is the Multiplayer (MP) version of the function
            * 
            * Returns the score after the round has completed
            */
            int gameRunMP( int tries, int player );

            
            /* Function: perRoundScore( int scores[] )
            *
            * shows the current score in between rounds
            * 
            * scores[] taken from gameRunMP, which stores the scores.
            * 
            * Returns void
            */
            void perRoundScore( int scores[] );

            /* Function: tieMP()
            *
            * both players have gotten the same score, they're asked if they'd like to play again.
            * This can only happen  in MP
            * 
            * Parameters:
            * scores[] taken from gameRunMP, which stores the scores.
            * 
            * Returns void
            */
            void tieMP( int scores[] );

            /* Function: winnerMP( int scores[], int winner)
            *
            * Function for displaying scores after a multiplayer match, and displaying the winner.
            * 
            * Parameters:
            * scores[] taken from gameRunMP, which stores the scores.
            * winner is the array value of the player that has won (0 --> player 1, 1 --> player 2)
            * 
            * Returns void
            */
            void winnerMP( int scores[], int winner );

        #pragma endregion

        #pragma region Singleplayer Functions

            /* Function: gameRunSP( diff_enum tries )
            *
            * launches promptGame, initiliases random number and clears terminal screen for game
            * this is the singleplayer (SP) version of the function
            * 
            * tries represents the difficulty enum
            * 
            * Returns void
            */
            void gameRunSP( diff_enum tries );

            /* Function: gameDiff()
            *
            * recursive game difficulty menu, after the choice, the player is sent to the startGame function
            * 
            * Returns void
            */
            void gameDiff();

        #pragma endregion

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
        * Returns the number of tries the user has left, if MP this is utilised to count the number of points the user has.
        */
        int promptGame( int r, int t ); 

        /* Function: playAgain() 
        * 
        * returns user to startGameMenu()
        * 
        * Returns void
        */
        void playAgain();

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

    #pragma endregion

#pragma endregion 

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

            system("cls");               // clear the console
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
                SorM(c);                // player mode menu
                break;

            case 'N':
                system("cls"); 
                printf("Exiting...");   // exits game (returns to startGame)
                break;

            default:
                startGameMenu(c);      // recurses back to startGameMenu.
        }
    }

    void SorM( char c ) 
    {
        #pragma region SorM Text
            system("cls");             // clear the console
            charPrettyPrint('-', 120);
            printf("\nPlease choose am gamemode: ");
            printf("\n 1] 1 Player Mode \n");
            printf("\n 2] 2 Player Mode \n Choice: ");
            scanf("%c", &c);
        #pragma endregion

        switch(c) 
        {
            case '1':
                gameDiff();
                break;

            case '2':
                MPInit();
                break;

            default:
                SorM(c);
        }
    }

    void gameDiff()
    {
        #pragma region text

            int c; //choice

            system("cls");
            charPrettyPrint('-', 120);
            printf("Please Choose a difficulty: ");
            printf("\n1] Easy: Unlimited Tries");
            printf("\n2] Medium: 25 Tries");
            printf("\n3] Hard: 10 Tries \n Choice: ");

            scanf("%d", &c);

        #pragma endregion

        switch(c)
        {
            case 1:
                gameRunSP(easy);
                break;
            
            case 2:
                gameRunSP(medium);
                break;
            
            case 3:
                gameRunSP(hard);
                break;
            
            default:
                gameDiff();
        }
    }

    void MPInit() 
    {
        static int scores[2] = { 0, 0 } ;
        int rounds, tries;

        rounds = MPRounds();
        for (int r = 0; r < rounds; r ++)
        {
            tries = MPTries(r);
            for(int i = 0; i < 2; i++ ) 
            {
                scores[i] += gameRunMP(tries, i + 1);
            }

            perRoundScore( scores );         //Show score at the end of the round
        }

        if( scores[0] == scores[1])
        {
            tieMP( scores );
        }
        else if( scores[0] > scores[1] )     // Player1 Won
        {
            winnerMP( scores, 0 );
        }
        else                                 // Player2 Won
        { 
            winnerMP( scores, 1 ); 
        }
    }

    int MPRounds()
    {
        int rounds;
        system("cls");

        printf("Enter the number of Rounds : ");
        scanf("%d", &rounds);

        if ( rounds > 0 ) 
        {
            return rounds;
        }
        else 
        {
            printf("Number of rounds invalid!");
            Sleep(1200);
            MPRounds();
        }
    }

    int MPTries(int iter) 
    {

        int t;

        system("cls");

        if (iter % 2 == 0)                 // Round is even --> player 1.
        { 
            printf("Player 1 |");
            charPrettyPrint( '-', 40 ); 
        } 
        else                               // Round is odd --> player 2.
        { 
            printf("Player 2 |");
            charPrettyPrint( '-', 40 ); 
        }

        printf("Enter the number of tries (>= 10):");
        scanf("%d", &t);

        if ( t >= 10) 
        {
            return t; 
        }
        else 
        {
            printf("Number of tries too small!");
            Sleep(1200);
            MPTries(iter);
        }
    }

    int gameRunMP( int tries, int player)
    {
        int r = RndGen(), score;               // This generates our random number for the game, between 1 and 100.
        system("cls");

        printf("Player %d | ", player );
        printf("Tries: %d", tries);
        charPrettyPrint( '-', 40 );

        int tries_new = promptGame(r, tries);
        printf("\n");
        score = tries_new;

        printf("%d\n", score);
        Sleep(1000);

        return score;
    }

    void gameRunSP(  diff_enum tries ) 
    {
        int r = RndGen();               // This generates our random number for the game, between 1 and 100.
        system("cls");

        (void) promptGame(r, tries);    // Return value isn't used in SP.
    } 

    int promptGame( int r, int t )
    {
        int userGuess = -1;     // value -1 is used for userGuess as it is out of bounds for the game
        printf("\n Tries: %d", t);
        printf("\nEnter Your Guess: ");
        scanf("%d", &userGuess);

        if (userGuess < 101 && userGuess > 0) 
        {
            if (t == 0) 
            {
                lost();
                return 0;
            }

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
                return t;
            }
        } 
        else 
        {
            printf("Invalid Value! Must be between 1 and 100.. \n"); 
            Sleep(2000);
            promptGame(r, t);
        }

    }

    #pragma region Win Loss And Checks

        void playAgain() 
        {
            Sleep(5000);
            system("cls");
            startGame();
        }

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
            Sleep(3000);
        }

        void lost() 
        {
            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("You have guessed incorrectly too many times and have lost the game!");
            Sleep(3000);
        }

        void perRoundScore( int scores[] ) 
        {
            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("Scores: \n");
            for (int i = 0; i < 2; i++) 
            {
                printf("Player %d: ", i + 1);
                printf("%d", scores[i]);
            }        
            Sleep(1000);
        }

        void tieMP( int scores[] )
        {
            char c;

            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("Scores: \n");
            for (int i = 0; i < 2; i++) 
            {
                printf("Player %d: ", i + 1);
                printf("%d", scores[i]);
            }        
            printf("\nBoth players have tied!");

            Sleep(1000);
            playAgain();
        }

        void winnerMP( int scores[], int winner ) 
        {
            system("cls");
            Sleep(30);
            charPrettyPrint('_', 100);
            printf("Scores: \n");
            for (int i = 0; i < 2; i++) 
            {
                printf("Player %d: ", i + 1);
                printf("%d", scores[i]);
                if (i == winner) { printf("----Winner! \n"); } else {printf("\n");}
            }

            Sleep(3000); //Wait an extra 5 seconds
            playAgain();
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

