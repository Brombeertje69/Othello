#include "game.ih"


int Game::play_round()
{
    //initialization
    char board[100];
    initialize_board(board);
    bool has_passed = false;
    char player = BLACK;

    print_board(board);

    while (true)
    {
        int move = get_move(player, board);
        
        if (move != 0)
        {
            std::cout << "player: " << (char)player 
                      << "\t move:" << move << '\n';
            make_move(move, player, board);
            has_passed = false;
            //print_board(board);         //uncomment to see every move
        } 

        else
        {
            if (has_passed == true)
            {
                break;
            }
            has_passed = true;
        }

        player = opponent(player);       //switch to other player
    }

    int score = get_score(board);
    
    return score;
}


