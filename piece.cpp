#include <piece.hpp>
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
    

    bool Piece::is_opponent_piece(const Piece& piece) const
    {
        return this->color != piece.color;
    }