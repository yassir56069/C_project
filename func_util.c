#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "___initFunc.h"

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