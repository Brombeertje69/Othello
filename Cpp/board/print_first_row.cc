#include "board.ih"

#include <iostream>

void print_first_row()
{
    std::cout << "  ";
    for (int col = 1; col != 9; col++)
    {
        std::cout << col << ' ';
    }

    std::cout << '\n';  
}