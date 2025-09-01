#include "Board.hpp"

// Include all the concrete piece types you will be creating
#include "Rook.hpp"
// #include "Knight.hpp"
 #include "Bishop.hpp"
// #include "Queen.hpp"
// #include "King.hpp"
// #include "Pawn.hpp"

// Constructor: Initializes the board with all pieces
Board::Board() {
   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            this->board[i][j] = nullptr;
        }
    }

    

    // White pieces (Row 0 and 1)
    this->board[0][0] = new Rook(0, 0, "white");
     //this->board[0][1] = new Knight(0, 1, "white");
     this->board[0][2] = new Bishop(0, 2, "white");
    // this->board[0][3] = new Queen(0, 3, "white");
    // this->board[0][4] = new King(0, 4, "white");
     this->board[0][5] = new Bishop(0, 5, "white");
    // this->board[0][6] = new Knight(0, 6, "white");
    this->board[0][7] = new Rook(0, 7, "white");
    // for (int j = 0; j < N; ++j) {
    //     this->board[1][j] = new Pawn(1, j, "white");
    // }


    // Black pieces (Row 6 and 7)
    // for (int j = 0; j < N; ++j) {
    //     this->board[6][j] = new Pawn(6, j, "black");
    // }
    this->board[7][0] = new Rook(7, 0, "black");
   //  this->board[7][1] = new Knight(7, 1, "black");
     this->board[7][2] = new Bishop(7, 2, "black");
    // this->board[7][3] = new Queen(7, 3, "black");
    // this->board[7][4] = new King(7, 4, "black");
     this->board[7][5] = new Bishop(7, 5, "black");
    // this->board[7][6] = new Knight(7, 6, "black");
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