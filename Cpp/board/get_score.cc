#include "board.ih"

int SQUARE_WEIGHTS[100] = {
0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
0, 120, -20,  20,   5,   5,  20, -20, 120,   0,
0, -20, -40,  -5,  -5,  -5,  -5, -40, -20,   0,
0,  20,  -5,  15,   3,   3,  15,  -5,  20,   0,
0,   5,  -5,   3,   3,   3,   3,  -5,   5,   0,
0,   5,  -5,   3,   3,   3,   3,  -5,   5,   0,
0,  20,  -5,  15,   3,   3,  15,  -5,  20,   0,
0, -20, -40,  -5,  -5,  -5,  -5, -40, -20,   0,
0, 120, -20,  20,   5,   5,  20, -20, 120,   0,
0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};

int get_score(char* board)
{
    int score = 0;
    for (int idx = 11; idx != 89; ++idx)
    {
        if (board[idx] == BLACK)
        {
            score += 1; //SQUARE_WEIGHTS[idx];
        }
        else if (board[idx] == WHITE)
        {
            score -= 1; //SQUARE_WEIGHTS[idx];
        }
    }
    return score;
}