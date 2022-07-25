#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "___initFunc.h"

int main() 
{
    srand(time(0));      // initialisation of srand for rnd() generated, using current time. Must be called once.
    setbuf(stdout, NULL);

    startGame();         //Display Game Screen

    return 0;
}


