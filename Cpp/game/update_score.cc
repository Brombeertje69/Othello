#include "game.ih"

void Game::update_score(int score)
{
    d_rounds += 1;   //increase the number of played rounds
    
    if (score > 0)
    {
        d_wins += 1;
    }
    else if (score < 0)
    {
        d_losses += 1;
    }
}