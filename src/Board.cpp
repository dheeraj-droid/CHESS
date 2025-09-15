#include "Board.hpp"


#include "Rook.hpp"
 #include "Knight.hpp"
 #include "Bishop.hpp"
 #include "Queen.hpp"
 #include "King.hpp"
 #include "Pawn.hpp"


Board::Board() {
   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            this->board[i][j] = nullptr;
        }
    }

    

   
    this->board[0][0] = new Rook(0, 0,PlayerColor::White);
     this->board[0][1] = new Knight(0, 1, PlayerColor::White);
     this->board[0][2] = new Bishop(0, 2, PlayerColor::White);
     this->board[0][3] = new Queen(0, 3,PlayerColor::White);
     this->board[0][4] = new King(0, 4, PlayerColor::White);
     this->board[0][5] = new Bishop(0, 5,PlayerColor::White);
    this->board[0][6] = new Knight(0, 6, PlayerColor::White);
    this->board[0][7] = new Rook(0, 7, PlayerColor::White);
     for (int j = 0; j < N; ++j) {
         this->board[1][j] = new Pawn(1, j, PlayerColor::White);
     }


    
     for (int j = 0; j < N; ++j) {
         this->board[6][j] = new Pawn(6, j, PlayerColor::Black);
     }
    this->board[7][0] = new Rook(7, 0, PlayerColor::Black);
    this->board[7][1] = new Knight(7, 1,PlayerColor::Black);
     this->board[7][2] = new Bishop(7, 2,PlayerColor::Black);
     this->board[7][3] = new Queen(7, 3, PlayerColor::Black);
     this->board[7][4] = new King(7, 4, PlayerColor::Black);
     this->board[7][5] = new Bishop(7, 5, PlayerColor::Black);
     this->board[7][6] = new Knight(7, 6, PlayerColor::Black);
    this->board[7][7] = new Rook(7, 7, PlayerColor::Black);
}


Board::~Board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            delete this->board[i][j];
        }
    }
}


bool Board::is_empty_and_valid(int x, int y) const {
    return (x >= 0 && x < N && y >= 0 && y < N && this->board[x][y] == nullptr);
}


Piece* Board::get_piece_at_pos(int x, int y) const {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        return this->board[x][y];
    }
    return nullptr; 
}

void Board::set_piece_at_pos(Piece* p,int x,int y)
{
    this->board[x][y] = p;
    return;
}


void Board::display() const
{
    for(int i = N-1;i>=0;i--)
    {
        for(int j=0;j<N;j++)
        {
            Piece* p = get_piece_at_pos(i,j);
            if(p==nullptr)
            cout << "." << " " ;
            else if(p->get_color() == PlayerColor::Black)
            cout <<"\033[1;30m" << p->get_code() << " \033[0m";
            else
            cout << p->get_code() << " ";
        }
        cout << endl;
    }
}