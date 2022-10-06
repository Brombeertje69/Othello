#include "board.ih"
#include<iostream>

int find_bracket(int move, char player, char* board, int direction)
{
    int square = move + direction;
    int first_square = square;

    char opp = opponent(player);
    //std::cout << "Opponent: " << (char)opp << '\n';

    while (board[square] == opp)
    {
        square += direction;
    }

    //std::cout << "square:" << (char)board[square] << '\n';
    // If a bracket is found, return it
    int bracket = (board[square] == player && square != first_square)?square:0; 
    return bracket;
}
