#include "board.ih"

void initialize_board(char* board)
{
    for (int idx = 0; idx != 100; ++idx)
    {
        int col = idx % 10;                                 // get col index
        int row = idx / 10;                                 // row idx

        bool col_between = col > 0 && col < 9;              // borders
        bool row_between = row > 0 && row < 9;  

        // set empty or border
        board[idx] = (col_between && row_between)?EMPTY:OUTER;  
    }

    // fill special cases
    board[44] = WHITE; 
    board[55] = WHITE;
    board[45] = BLACK;
    board[54] = BLACK;
}