#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "___initFunc.h"

#pragma region Game Functions
// These functions are utilised in running the game

    void startGame()
    {
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