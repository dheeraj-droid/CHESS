#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "piece.hpp"

class Queen : public Piece {
public:
  
    Queen(int r, int c, string color);
    vector<pair<int, int>> get_valid_moves(const Board& board) const override;
};

#endif