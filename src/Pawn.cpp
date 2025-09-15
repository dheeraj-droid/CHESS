#include "Pawn.hpp"


Pawn::Pawn(int r, int c, PlayerColor color):Piece(PieceType::Pawn,r,c,color),can_en_passant(false) {
    if(color == PlayerColor::White)
    val = 1;
    else
    val = -1;
}



 void Pawn::add_valid_move_single( int i,int j,vector<pair<int,int>>& moves,const Board& board,bool can_kill) const
     {
         if(i<N && j < N && i>=0 && j >= 0 && !can_kill)
        {
            Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else 
            return;
        }
        else if(i<N && j < N && i>=0 && j >= 0 && can_kill)
        {
             Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            return;
            else if(this->is_opponent_piece(*p))
            {      
                moves.push_back({i,j});   
            }
        }
     }


    vector<pair<int,int>> Pawn::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        if(board.is_empty_and_valid(x+val,y))
        {
            add_valid_move_single(x+val,y,moves,board,false);
            if(!this->has_moved && board.is_empty_and_valid(x+val+val,y))
            add_valid_move_single(x+val+val,y,moves,board,false);
        }

        
        add_valid_move_single(x+val,y-1,moves,board,true);
        add_valid_move_single(x+val,y+1,moves,board,true);

      

        return moves;
    }


