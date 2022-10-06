#include "game.ih"

void Game::play(int rounds)
{

    for (int idx = 0; idx != rounds; ++idx)
    {
        int score = play_round();               // play 1 round
        update_score(score);                    // update the score
    }
    display_score();                            // display final results
}

