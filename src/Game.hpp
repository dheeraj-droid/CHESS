#ifndef GAME_HPP
#define GAME_HPP

#include "piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"

class Game
{
    private:
    Board new_board1;
    PlayerColor curr_player_color;
   
    public:
    Game();
   
    bool is_promotion_possible(Piece* curr_piece,int y) const;
    void display_board_and_prompt() const;
    string get_player_move() const;
    void switch_player();
     Piece* promote_pawn(char choice,pair<int,int>& after,PlayerColor color) ;
    bool validate_move(const vector<pair<int, int>>& positions) const;
    void execute_move(const vector<pair<int, int>>& positions);
    bool check_game_end() ;
  
    void play();
    

};

#endif