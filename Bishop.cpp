#include <Bishop.hpp>

Bishop::Bishop(int r, int c, string color):Piece("Bishop",r,c,color){}



    vector<pair<int,int>> Bishop::get_valid_moves(const Board& board) const 
    {
        vector<pair<int,int>> moves;
        pair<int,int> curr_pos = this->get_curr_pos();
        int x = curr_pos.first;
        int y = curr_pos.second;

        int i = x + 1;
        int j = y + 1;
        while(i<N && j < N && board.is_empty_and_valid(i,y))
        {
            moves.push_back({i,y});
            i++;
            j++;
        }

         i = x-1;
         j = y - 1; 
        while(i>=0 && j>=0 && board.is_empty_and_valid(i,y))
        {
            moves.push_back({i,y});
            i--;
            j--;
        }

         i = x - 1;
         j = y + 1;
        while(j<N && i>=0 && board.is_empty_and_valid(x,j))
        {
            moves.push_back({x,j});
            j++;
            i--;
        }

        i = x + 1;
        j = y - 1;
        while(j>=0 && i<N && board.is_empty_and_valid(x,j))
        {
            moves.push_back({x,j});
            j--;
            i++;
        }

        return moves;
    }


