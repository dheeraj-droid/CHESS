#include <Queen.hpp>

Queen::Queen(int r, int c, string color):Piece("QUEEN",r,c,color){}

    vector<pair<int,int>> Queen::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        int i = x + 1;
        while(i<N )
        {
             Piece* p  =  board.get_piece_at_pos(i,y);
            if(p==nullptr)
            moves.push_back({i,y});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,y});
                break;
            }
            else
            break;
            i++;
        }

         i = x-1;
        while(i>=0)
        {
            Piece* p  =  board.get_piece_at_pos(i,y);
            if(p==nullptr)
            moves.push_back({i,y});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,y});
                break;
            }
            else
            break;
            i--;
        }

        int j = y + 1;
        while(j<N )
        {
             Piece* p  =  board.get_piece_at_pos(x,j);
            if(p==nullptr)
            moves.push_back({x,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({x,j});
                break;
            }
            else
            break;
            j++;
        }

        j = y - 1;
        while(j>=0)
        {
             Piece* p  =  board.get_piece_at_pos(x,j);
            if(p==nullptr)
            moves.push_back({x,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({x,j});
                break;
            }
            else
            break;
            j--;
        }

         i = x + 1;
         j = y + 1;
        while(i<N && j < N)
        {
             Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,j});
                break;
            }
            else
            break;
            i++;
            j++;
        }

         i = x-1;
         j = y - 1; 
        while(i>=0 && j>=0)
        {
             Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,j});
                break;
            }
            else
            break;
            i--;
            j--;
        }

         i = x - 1;
         j = y + 1;
        while(j<N && i>=0)
        {
             Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,j});
                break;
            }
            else
            break;
            j++;
            i--;
        }

        i = x + 1;
        j = y - 1;
        while(j>=0 && i<N)
        {
             Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {
                moves.push_back({i,j});
                break;
            }
            else
            break;
            j--;
            i++;
        }

        return moves;
    }


