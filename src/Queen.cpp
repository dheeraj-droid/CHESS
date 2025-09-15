#include "Queen.hpp"

Queen::Queen(int r, int c, PlayerColor color):Piece(PieceType::Queen ,r,c,color){}

    vector<pair<int,int>> Queen::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        vector<int> dx = {0,0,-1,1,-1,1,-1,1};
        vector<int> dy = {-1,1,0,0,-1,-1,1,1};

        for(int i = 0;i<8;i++)
        {
            add_valid_move_continuous(x+dx[i],y+dy[i],moves,board,dx[i],dy[i]);
        }

        return moves;
    }


