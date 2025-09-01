#define N 8
#include <Board.hpp>

bool Board::is_empty_and_valid(int x,int y) const{
    return (x<N && y<N && x>=0 && y>=0 && (this->board[x][y] == nullptr));
}

Piece* Board::get_piece_at_pos(int x,int y) const{
    return this->board[x][y];
}