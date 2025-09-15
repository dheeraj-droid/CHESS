#ifndef PIECE_HPP
#define PIECE_HPP
#include "types.hpp"
#include "Board.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
class Board;
using namespace std;

class Piece{
protected:
PieceType type;
int row;
int col;
bool is_captured;
PlayerColor color;
string code;
bool has_moved;


 void add_valid_move_single(const int i,const int j,vector<pair<int,int>>& moves,const Board& board) const;
  void add_valid_move_continuous(const int i,const int j,vector<pair<int,int>>& moves,const Board& board,const int di,const int dj) const;


    public:

    Piece(PieceType type,int x,int y,PlayerColor color);
    virtual ~Piece();
    PieceType get_type() const;
    string get_code() const;
    pair<int,int> get_curr_pos() const;
     void set_curr_pos(const int x, const int y );
    bool get_if_moved() const;
    bool get_if_captured() const;

    void set_if_moved(bool val) ;
    void set_capture( bool val);

    Piece* promote(Piece* curr_piece) ;
    virtual vector<pair<int,int>> get_valid_moves(const Board& board) const  = 0;
     bool is_opponent_piece(const Piece& piece) const ;
        PlayerColor get_color() const ;
        bool type_of_capture(PieceType type, int x, int y, int dx, int dy, int direction) const;
      bool can_be_captured_in_a_direction(const Board& board,int nx,int ny,int x,int y,int type) const;
     bool can_be_captured(const Board& board) const;

};


#endif