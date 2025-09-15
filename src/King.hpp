#ifndef KING_HPP
#define KING_HPP

#include "piece.hpp"

class King : public Piece {
public:
  
    King(int r, int c, PlayerColor color);
    bool check_castling( const Board& board,int x,int y) const;
    vector<pair<int, int>> get_valid_moves(const Board& board)const  override;
    bool is_check(const Board& board) const;
};

#endif