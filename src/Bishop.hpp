#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "piece.hpp"

class Bishop : public Piece {
public:
  
    Bishop(int r, int c, string color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
};

#endif