#include "King.hpp"

King::King(int r, int c, string color):Piece("K",r,c,color){}

    vector<pair<int,int>> King::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

         vector<int> dx = {0,0,-1,1,-1,1,-1,1};
        vector<int> dy = {-1,1,0,0,-1,-1,1,1};

        for(int i = 0;i<8;i++)
        {
            add_valid_move_single(x+dx[i],y+dy[i],moves,board);
        }
        
        return moves;
    }


