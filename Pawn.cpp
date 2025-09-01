#include "Pawn.hpp"

Pawn::Pawn(int r, int c, string color):Piece("P",r,c,color){
    if(color == "white")
    val = 1;
    else
    val = -1;
}


    vector<pair<int,int>> Pawn::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

       int i = x + val;
       int j = y;

        if(!this->has_moved && board.is_empty_and_valid(i,j) &&  board.is_empty_and_valid(i+val,j))
        {
            moves.push_back({i+val,j});
        }


       if(board.is_empty_and_valid(i,j))
        moves.push_back({i,j});

       j = y - 1;
       Piece* p = board.get_piece_at_pos(i,j);
       if( i<N && i>=0 && j<N && j>=0 && p!=nullptr && this->is_opponent_piece(*p))
       moves.push_back({i,j});

       j = y + 1;
        p = board.get_piece_at_pos(i,j);
       if( i<N && i>=0 && j<N && j>=0 && p!=nullptr && this->is_opponent_piece(*p))
       moves.push_back({i,j});



       
        return moves;
    }


