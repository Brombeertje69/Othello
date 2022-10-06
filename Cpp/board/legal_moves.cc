#include "board.ih"

#include<vector>
#include<algorithm> 
#include<unordered_map> // map instead of enum
#include<string>

std::unordered_map<std::string, int> directions 
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

std::vector<int> legal_moves(char player, char* board)
{
    std::vector<int> owned_squares = find_player_squares(player, board); 

    std::vector<int> moves;     // find all squares belonging to player

  
    for (int move : owned_squares)
    {
        for (std::pair<std::string, int> element : directions)
        {
            int direction = element.second;
            int legal_move = find_legal(move, player, board, direction);

            if (legal_move != 0)
            {
                moves.push_back(legal_move);
            }
        }
    }  
  
    // remove duplicates:  
    std::sort(moves.begin(), moves.end());  //Unique only works on sorted
    auto it = std::unique(moves.begin(), moves.end()); //find last duplicated
    moves.resize(std::distance(moves.begin(), it)); //remove duplicates

    return moves;
}