#include "King.hpp"

King::King(int r, int c, PlayerColor color):Piece(PieceType::King,r,c,color){}



    bool King::is_check(const Board& board) const
    {
        if(this->can_be_captured(board))
        return true;
        
        return false;
    }


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
        
        if(!this->get_if_moved() && !this->is_check(board))
        {
           if(check_castling(board,-1))
           {
                moves.push_back({x,y-2});
           }

           if(check_castling(board,1))
           {
                moves.push_back({x,y+2});
           }
        }

        return moves;
    }

    bool King::check_castling( const Board& board,int dy) const
    {
        auto king_pos = this->get_curr_pos();
        int x = king_pos.first;
        int y = king_pos.second;
        Piece* rook = (dy<0)?board.get_piece_at_pos(x,y+4*dy):board.get_piece_at_pos(x,y+3*dy);
        if(rook == nullptr || rook->get_if_moved() )
        return false;
        int ny = y + dy;
        Piece* curr_piece = board.get_piece_at_pos(x,ny);

        while(curr_piece != rook)
        {
            if(curr_piece != nullptr)
            return false;

           Piece* temp_piece = new King(x,ny,this->get_color());
           if(temp_piece->can_be_captured(board))
           return false;
            
            ny+=dy;
            curr_piece = board.get_piece_at_pos(x,ny);
        }

        return true;
    }


