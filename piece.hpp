#ifndef PIECE_HPP
#define PIECE_HPP

#include "Board.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Piece{
protected:
string type;
int row;
int col;
bool is_captured;
string color;
bool has_moved;

public:

    Piece(string type,int x,int y,string color);
    virtual ~Piece();
    string get_type() const;
    pair<int,int> get_curr_pos() const;
     void set_curr_pos(const int x, const int y );
    bool get_if_moved() const;
    bool get_if_captured() const;

    void set_if_moved(bool val) ;
    void set_capture( bool val);

    virtual vector<pair<int,int>> get_valid_moves(const Board& board) const  = 0;
     bool is_opponent_piece(const Piece& piece) const ;
        string get_color() const ;
      void add_valid_move_single(const int i,const int j,vector<pair<int,int>>& moves,const Board& board) const;
      void add_valid_move_continuous(const int i,const int j,vector<pair<int,int>>& moves,const Board& board,const int di,const int dj) const;

};


#endif