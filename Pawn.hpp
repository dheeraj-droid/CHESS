#ifndef PAWN_HPP
#define PAWN_HPP

#include "piece.hpp"

class Pawn : public Piece {
    private:
    int val;
public:
  
    Pawn(int r, int c, string color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
     void add_valid_move_single(const int i,const int j,vector<pair<int,int>>& moves,const Board& board,bool can_kill) const;
};

#endif