#include "strategies.ih"

#include<vector>
#include<string.h>
#include<iostream>

#include<unistd.h> 

Move minimax(char player, char* board, char maximizer, 
             int depth, int max_depth)
{
    Move best_move;                         // return value

    if (depth == max_depth)
    {
        best_move = {0, get_score(board)};  // static evaluate score
    }
    else
    {
        std::vector<int> moves = legal_moves(player, board);

        /*
        std::cout << "depth:" << depth << '\n';
        std::cout << '\n' << "Legal: ";
        for (int elem : moves)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
        sleep(1);
        */
        
        if (moves.size() != 0)
        {
            char opp = opponent(player);    // change to other player
            int best_score = -10000;         // initialize current best score

            ++depth;                        // increase the depth
            for (int move : moves)
            {
                //std::cout << '\n' <<"Testing: " << move << '\n';
                //sleep(1);
                char copy[100];                // reserve array for the copy
                strcpy(copy, board);           // copy the board to keep track

                make_move(move, player, copy); 
                //sleep(1);

                int score = minimax(opp, copy, maximizer, 
                                 depth, max_depth).value;

                if (score > best_score)
                {
                    best_score = score;         // update the best score
                    best_move = {move, score};
                }
            }

        }
        else
        {
            best_move = {0, get_score(board)};  // static evaluate score
        }
    }

    best_move.value = -best_move.value; //Return the negative value 

    /*
    if (depth < 5)
    {
        //sleep(1);
        std::cout << "depth:" << depth << '\n'; 
        std::cout << "best move: " << best_move.move << '\n';
        std::cout << "best value: " << best_move.value << '\n';
    }
    */    

    return best_move;
}