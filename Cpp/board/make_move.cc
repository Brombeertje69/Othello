#include "board.ih"

#include <iostream>

// Need to loop over the directions, so using a map instead of enum!
#include <unordered_map>
#include <string>
std::unordered_map<std::string, int> Directions 
{
    {"UP", -10},
    {"UP_RIGHT", -9},
    {"RIGHT",  1},
    {"DOWN_RIGHT", 11},
    {"DOWN",  10},
    {"DOWN_LEFT", 9},
    {"LEFT", -1},
    {"UP_LEFT", -11}
};

void make_move(int move, char player, char* board)
{
    board[move] = player;   // capture the move field

    for (std::pair<std::string, int> element : Directions)
    {
        int direction = element.second;
        //std::cout << direction << '\n';

        int bracket = find_bracket(move, player, board, direction);

        //std::cout << bracket << '\n';
        if (bracket != 0)
        {
            //std::cout << bracket << '\n';
            make_flip(move, player, board, direction, bracket);
        }
    }

    //print_board(board);
}