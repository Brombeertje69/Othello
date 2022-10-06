#include "board.ih"

void make_flip(int move, char player, char* board, int direction, int bracket)
{
    int square = move + direction;

    while (square != bracket)
    {
        board[square] = player;
        square += direction;
    }
}
