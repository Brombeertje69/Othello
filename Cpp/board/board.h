#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <vector>
#include <unordered_map>

// basic functions
void initialize_board(char* board);
char opponent(char player);
int get_score(char* board);
//std::unordered_map<std::string, int> Directions;

 // display functionality
void print_board(char* board);       
void print_first_row();

// movement
void make_move(int move, char player, char* board);
void make_flip(int move, char player, char* board, int direction, int bracket);
int find_bracket(int move, char player, char* board, int direction);

// legal moves
std::vector<int> find_player_squares(char player, char* board);
std::vector<int> legal_moves(char player, char* board);
int find_legal(int move, char player, char* board, int direction);

#endif