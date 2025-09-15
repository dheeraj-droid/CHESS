#include "King.hpp"

King::King(int r, int c, PlayerColor color):Piece(PieceType::King,r,c,color){}



    



    vector<pair<int,int>> King::get_valid_moves(const Board& board)  const
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
        /*
        if(!this->get_if_moved())
        {
           if(check_castling(board,x-4,y))
           {

           }

           if(check_castling(board,x+3,y))
           {
        
           }
        }
*/
        return moves;
    }

    bool King::check_castling( const Board& board,int x,int y) const
    {
        //half implementation - still needs to be implemented   
        Piece* curr_piece = board.get_piece_at_pos(x,y);
        if(!curr_piece->get_if_moved())
        {
            for(int i = 1;i<=3;i++)
            {
                if(board.get_piece_at_pos(x+i,y) != nullptr)
                return false;
            }

            return true;
        }
        return false;
    }


