#include "Knight.hpp"

Knight::Knight(int r, int c, PlayerColor color):Piece(PieceType::Knight,r,c,color){}

    vector<pair<int,int>> Knight::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        vector<int> dir_x = {1,1,-1,-1,2,2,-2,-2};
        vector<int> dir_y = {2,-2,2,-2,1,-1,1,-1};
 
        for(int k = 0;k<8;k++)
        {
        int i = x + dir_x[k];
        int j = y + dir_y[k];
        add_valid_move_single(i,j,moves,board);
        }
        

        return moves;
    }


