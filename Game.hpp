#ifndef GAME_HPP
#define GAME_HPP

#include "piece.hpp"
class Game
{
    private:
    Board new_board1;
    string curr_player;
   
    public:
    Game();
   

    void play()  const;
    

};

#endif