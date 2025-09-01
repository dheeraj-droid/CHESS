#include <Rook.hpp>

Rook::Rook(int r, int c, string color):Piece("ROOK",r,c,color){}

    vector<pair<int,int>> Rook::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        int i = x + 1;
        while(i<N && board.is_empty_and_valid(i,y))
        {
            moves.push_back({i,y});
            i++;
        }

         i = x-1;
        while(i>=0 &&  board.is_empty_and_valid(i,y))
        {
            moves.push_back({i,y});
            i--;
        }

        int j = y + 1;
        while(j<N && board.is_empty_and_valid(x,j))
        {
            moves.push_back({x,j});
            j++;
        }

        j = y - 1;
        while(j>=0 && board.is_empty_and_valid(x,j))
        {
            moves.push_back({x,j});
            j--;
        }

        return moves;
    }


