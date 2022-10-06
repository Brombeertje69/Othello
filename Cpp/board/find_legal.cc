#include "board.ih"
#include<iostream>

int find_legal(int move, char player, char* board, int direction)
{
    int square = move + direction;
    int first_square = square;

    char opp = opponent(player);

    while (board[square] == opp)
    {
        square += direction;
    }

    // If a bracket is found, return it
    /*
    std::cout << (char)board[square] << " and " << 
                (int) (board[square] == EMPTY) << " and " <<
                (int)(square != first_square) << " and " <<
                (int)(board[square] == EMPTY && square != first_square); 
    */
    int bracket = (board[square] == EMPTY && square != first_square)?square:0; 

    //std::cout << " \t Bracket: " << bracket <<'\n';
    return bracket;
}
