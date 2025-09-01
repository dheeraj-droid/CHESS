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
    virtual vector<pair<int,int>> get_valid_moves(const Board& board) const  = 0;
     bool is_opponent_piece(const Piece& piece) const ;

};


#endif