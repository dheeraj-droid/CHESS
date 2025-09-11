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

    

   
    this->board[0][0] = new Rook(0, 0, "white");
     this->board[0][1] = new Knight(0, 1, "white");
     this->board[0][2] = new Bishop(0, 2, "white");
     this->board[0][3] = new Queen(0, 3, "white");
     this->board[0][4] = new King(0, 4, "white");
     this->board[0][5] = new Bishop(0, 5, "white");
    this->board[0][6] = new Knight(0, 6, "white");
    this->board[0][7] = new Rook(0, 7, "white");
     for (int j = 0; j < N; ++j) {
         this->board[1][j] = new Pawn(1, j, "white");
     }


    
     for (int j = 0; j < N; ++j) {
         this->board[6][j] = new Pawn(6, j, "black");
     }
    this->board[7][0] = new Rook(7, 0, "black");
    this->board[7][1] = new Knight(7, 1, "black");
     this->board[7][2] = new Bishop(7, 2, "black");
     this->board[7][3] = new Queen(7, 3, "black");
     this->board[7][4] = new King(7, 4, "black");
     this->board[7][5] = new Bishop(7, 5, "black");
     this->board[7][6] = new Knight(7, 6, "black");
    this->board[7][7] = new Rook(7, 7, "black");
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
            else if(p->get_color() == "black")
            cout <<"\033[1;30m" << p->get_type() << " \033[0m";
            else
            cout << p->get_type() << " ";
        }
        cout << endl;
    }
}