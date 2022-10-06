#include "board.ih"

std::vector<int> find_player_squares(char player, char* board)
{
    std::vector<int> owned_squares;
    for (int idx = 11; idx != 89; ++idx)
    {
        if (board[idx] == player)
        {
            owned_squares.push_back(idx);
        }
    }
    return owned_squares;
}
