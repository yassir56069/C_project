#ifndef ___INITFUNC_H_    // Include guard
    #define ___INITFUNC_H_

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

#endif                    // ___INITFUNC_H_