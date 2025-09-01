#include "Knight.hpp"

Knight::Knight(int r, int c, string color):Piece("K",r,c,color){}

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
        if(i<N && j < N && i>=0 && j >= 0)
        {
            Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,j});
                
            }
        }
    }
        

        return moves;
    }


