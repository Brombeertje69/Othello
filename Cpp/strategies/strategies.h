#ifndef INCLUDED_STRATEGIES_
#define INCLUDED_STRATEGIES_

struct Move
{
    int move;
    int value;
};

int random(char player, char* board);
Move minimax(char player, char* board, char maximizer, 
                int depth, int max_depth);
#endif