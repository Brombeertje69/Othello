#include "game.ih"

int Game::get_move(char player, char* board)
{
    int move = 0;

    if (player == BLACK)
    {
        //move = random(player, board);
        move = minimax(player, board, player, 0, 5).move;
    }
    else
    {
        move = minimax(player, board, player, 0, 1).move;
        //move = random(player, board);
    }

    return move;
}