#include "game.ih"

#include<iostream> 

void Game::display_score()
{
    std::cout << "----- Results -----" << '\n';
    std::cout << "Black won: \t\t" << d_wins << '\n'; 
    std::cout << "White won: \t\t" << d_losses << '\n'; 
    std::cout << "Ties: \t\t\t" << d_rounds - (d_wins + d_losses) << '\n'; 
}