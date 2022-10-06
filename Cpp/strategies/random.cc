#include "strategies.ih"
#include<vector>
#include<stdlib.h> 

int random(char player, char* board)
{
    std::vector<int> moves = legal_moves(player, board); //get available moves

    int element = 0; 
    if (moves.size() != 0)
    {
        int random = rand() % moves.size();
        element = moves[random];
    }

    return element;
}