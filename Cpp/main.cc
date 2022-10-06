#include "main.ih"
#include "shared/enum.h"
#include <time.h> //header for time


int main()
{
    srand(time(NULL)); // call only once and preferably at the start of main 
    Game game;
    game.play(1);
}

