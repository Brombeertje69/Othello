#include "board.ih"

#include <iostream>

void print_board(char* board)
{
    print_first_row();

    std::cout << "1 ";                          // start
    for (int idx = 11; idx != 89; ++idx)
    {
        int col = idx % 10;                     // get col idx
        int row = idx / 10 + 1;                 // get row idx

        if (col == 9)
        {
             std::cout << '\n' << row << ' ';   // go next line
        }
        else if (col != 0)
        {
            std::cout << board[idx] << ' ';     // output the values
        }
    }
    std::cout << '\n' << '\n';                           // close the last line
}