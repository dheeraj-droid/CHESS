#ifndef BOARD_HPP
#define BOARD_HPP

#define N 8
class Piece;
class Board{

    private:
    Piece* board[N][N];

    public:
    Board();
    ~Board();

    Piece* get_piece_at_pos(int x,int y) const;
    bool is_empty_and_valid(int x,int y) const;
    void set_piece_at_pos(Piece* p,int x,int y);
    void display() const;

};

#endif