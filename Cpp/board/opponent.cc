#include "board.ih"

char opponent(char player)
{
   return (player == BLACK)?WHITE:BLACK; 
}