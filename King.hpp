#ifndef KING_HPP
#define KING_HPP

#include "piece.hpp"

class King : public Piece {
public:
  
    King(int r, int c, string color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
};

#endif