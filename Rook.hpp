#ifndef ROOK_HPP
#define ROOK_HPP

#include "piece.hpp"

class Rook : public Piece {
public:
  
    Rook(int r, int c, string color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
};

#endif