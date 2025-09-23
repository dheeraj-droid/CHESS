#include "piece.hpp"
using namespace std;

Piece::Piece(PieceType type, int r, int c, PlayerColor color) : type(type), row(r), col(c), color(color), is_captured(false), has_moved(false) {
    if(this->type == PieceType::Bishop)
    this->code = "♗";
    else if(this->type == PieceType::Knight)
    this->code = "♘";
     else if(this->type == PieceType::Rook)
    this->code = "♖";
     else if(this->type == PieceType::King)
    this->code = "♔";
     else if(this->type == PieceType::Queen)
    this->code = "♕";
    else
    this->code = "♙";
}

PieceType Piece::get_type() const
{
    return this->type;
}
 string Piece::get_code() const
 {
    return this->code;
 }
pair<int, int> Piece::get_curr_pos() const
{
    return {this->row, this->col};
}

void Piece::set_curr_pos(const int x, const int y)
{
    this->row = x;
    this->col = y;
    return;
}

bool Piece::is_opponent_piece(const Piece &piece) const
{
    return this->color != piece.color;
}

void Piece::add_valid_move_single(int i, int j, vector<pair<int, int>> &moves, const Board &board) const
{
    if (i < N && j < N && i >= 0 && j >= 0)
    {
        Piece *p = board.get_piece_at_pos(i, j);
        if (p == nullptr)
            moves.push_back({i, j});
        else if (this->is_opponent_piece(*p))
        {
            moves.push_back({i, j});
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

void Piece::set_capture(bool val)
{
    this->is_captured = val;
}

PlayerColor Piece::get_color() const
{
    return this->color;
}

void Piece::add_valid_move_continuous(int i, int j, vector<pair<int, int>> &moves, const Board &board, const int di, const int dj) const
{

    while (i < N && j < N && i >= 0 && j >= 0)
    {
        Piece *p = board.get_piece_at_pos(i, j);
        if (p == nullptr)
            moves.push_back({i, j});
        else if (this->is_opponent_piece(*p))
        {
            moves.push_back({i, j});
            break;
        }
        else
            break;

        i += di;
        j += dj;
    }
}

bool Piece::can_be_captured_in_a_direction(const Board &board, int nx, int ny, int x, int y, int direction) const
{
    //0 - orthogonal,1 - diagonal
        int dx = x + nx;
        int dy = y + ny;
        
        while (dx >= 0 && dx < N && dy >= 0 && dy < N)
        {
            Piece *first_piece = board.get_piece_at_pos(dx, dy);
            if (first_piece != nullptr)
            {
                if (this->is_opponent_piece(*first_piece))
                {
                    PieceType type = first_piece->get_type();
                    if (type_of_capture(type,x,y,dx,dy,direction))
                        return true;
                }

                break;
            }
            dx += nx;
            dy += ny;
        }
    

    return false;
}

bool Piece::type_of_capture(PieceType type, int x, int y, int dx, int dy, int direction) const
{
    if (direction == 0)
        return (type == PieceType::Rook  || type == PieceType::Queen || (abs((dx - x)) == 1 && type == PieceType::King) || (abs((dy - y)) == 1 && type == PieceType::King));
    else 
        return (type == PieceType::Bishop || type == PieceType::Queen || (abs((dx - x)) == 1 && type == PieceType::King) || (abs((dy - y)) == 1 && type == PieceType::King));
}

bool Piece::can_be_captured(const Board &board) const
{
    auto pos = this->get_curr_pos();
    int x = pos.first;
    int y = pos.second;

    // 1. Check for sliding attacks (Rook, Bishop, Queen) and King attacks
    int dx_orth[] = {0, 0, 1, -1};
    int dy_orth[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        if (can_be_captured_in_a_direction(board, dx_orth[i], dy_orth[i], x, y, 0))
            return true;
    }
    int dx_diag[] = {1, 1, -1, -1};
    int dy_diag[] = {-1, 1, -1, 1};
    for (int i = 0; i < 4; ++i) {
        if (can_be_captured_in_a_direction(board, dx_diag[i], dy_diag[i], x, y, 1))
            return true;
    }

    // 2. Check for Knight attacks directly
    int dx_knight[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy_knight[] = {2, -2, 2, -2, 1, -1, 1, -1};
    for (int k = 0; k < 8; k++) {
        int i = x + dx_knight[k];
        int j = y + dy_knight[k];
        if (i >= 0 && i < N && j >= 0 && j < N) {
            Piece* knight = board.get_piece_at_pos(i, j);
            if (knight != nullptr && is_opponent_piece(*knight) && knight->get_type() == PieceType::Knight) {
                return true;
            }
        }
    }

    // 3. Check for Pawn attacks directly
    int pawn_dir = (this->color == PlayerColor::White) ? 1 : -1;
    int pawn_attack_row = x + pawn_dir;
    for (int j_offset : {-1, 1}) {
        int i = pawn_attack_row;
        int j = y + j_offset;
        if (i >= 0 && i < N && j >= 0 && j < N) {
            Piece* pawn = board.get_piece_at_pos(i, j);
            if (pawn != nullptr && is_opponent_piece(*pawn) && pawn->get_type() == PieceType::Pawn) {
                return true;
            }
        }
    }

    return false; 
}

Piece::~Piece() {}