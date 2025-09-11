#include "piece.hpp"
using namespace std;
 
    Piece::Piece(std::string type, int r, int c, string color) : type(type), row(r), col(c), color(color), is_captured(false), has_moved(false) {}

    string  Piece::get_type() const
    {
        return this->type;
    }
    pair<int,int>  Piece::get_curr_pos()  const
    { 
        return  {this->row,this->col};
    }

    void Piece::set_curr_pos(const int x, const int y )
    {
        this->row = x;
        this->col = y;
        return;
    }
    


    bool Piece::is_opponent_piece(const Piece& piece) const
    {
        return this->color != piece.color;
    }

     void Piece::add_valid_move_single( int i,int j,vector<pair<int,int>>& moves,const Board& board) const
     {
         if(i<N && j < N && i>=0 && j >= 0)
        {
            Piece* p  =  board.get_piece_at_pos(i,j);
            if(p==nullptr)
            moves.push_back({i,j});
            else if(this->is_opponent_piece(*p))
            {      
                moves.push_back({i,j});   
            }
        }
     }


      bool Piece::get_if_moved() const
      {
        return this->has_moved;
      }

    bool Piece::get_if_captured() const
    {
        return this->is_captured;
    }


    void Piece::set_if_moved(bool val) 
    {
        this->has_moved = val;
    }

    void Piece::set_capture( bool val)
    {
        this->is_captured = val;
    }

     string Piece::get_color() const
     {
        return this->color;
     }

     void Piece::add_valid_move_continuous( int i,int j,vector<pair<int,int>>& moves,const Board& board,const int di,const int dj) const
     {
        
        while(i<N && j < N && i>=0 && j >= 0)
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

            i+=di;
            j+=dj;
        }
     }

   


    Piece::~Piece(){}