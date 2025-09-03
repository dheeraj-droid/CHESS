#include "Bishop.hpp"

Bishop::Bishop(int r, int c, string color):Piece("B",r,c,color){}

    vector<pair<int,int>> Bishop::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = -1;i<=1;i+=2)
        {
            for(int j = -1;j<=1;j+=2)
            {
                add_valid_move_continuous(x+i,y+j,moves,board,i,j);
            }
        }

        return moves;
    }


