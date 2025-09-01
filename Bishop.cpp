#include "Bishop.hpp"

Bishop::Bishop(int r, int c, string color):Piece("B",r,c,color){}


    vector<pair<int,int>> Bishop::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        int i = x + 1;
        int j = y + 1;
        while(i<N && j < N )
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
        while(i>=0 && j>=0 )
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
        while(j<N && i>=0 )
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
        while(j>=0 && i<N )
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


