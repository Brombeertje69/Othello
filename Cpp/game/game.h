#ifndef INCLUDED_GAME_
#define INCLUDED_GAME_

 
class Game
{
    int d_wins = 0;
    int d_losses =0;
    int d_rounds = 0;

    public:
        Game() = default;

        void play(int rounds);
        int play_round();
        void display_score();
        void reset();

    private:
        int get_move(char player, char* board);
        void update_score(int score);
};

#endif