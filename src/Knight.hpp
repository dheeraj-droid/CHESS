#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "piece.hpp"

class Knight : public Piece {
public:
  
    Knight(int r, int c, PlayerColor color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
};

#endif