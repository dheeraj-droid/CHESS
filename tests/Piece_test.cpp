#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Board.hpp"
#include "Pawn.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "piece.hpp"
#include <utility>

using ::testing::UnorderedElementsAre;

class PieceTest : public ::testing::Test {
protected:
    Board board;
    void SetUp() override {
        // Clear the board for specific test setups
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board.set_piece_at_pos(nullptr, i, j);
            }
        }
    }
    // Clean up memory after each test
    void TearDown() override {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                Piece* piece = board.get_piece_at_pos(i, j);
                if (piece != nullptr) {
                    delete piece;
                    board.set_piece_at_pos(nullptr, i, j);
                }
            }
        }
    }
};

// Test for set_curr_pos and get_curr_pos
TEST_F(PieceTest, SetAndGetPosition) {
    Piece* myPawn = new Pawn(1, 1, PlayerColor::White);
    EXPECT_EQ(myPawn->get_curr_pos(), std::make_pair(1, 1));

    myPawn->set_curr_pos(2, 2);
    EXPECT_EQ(myPawn->get_curr_pos(), std::make_pair(2, 2));

    delete myPawn;
}

// Test for set_if_moved and get_if_moved
TEST_F(PieceTest, SetAndGetIfMoved) {
    Piece* myPawn = new Pawn(1, 1, PlayerColor::White);
    EXPECT_FALSE(myPawn->get_if_moved());

    myPawn->set_if_moved(true);
    EXPECT_TRUE(myPawn->get_if_moved());

    myPawn->set_if_moved(false);
    EXPECT_FALSE(myPawn->get_if_moved());

    delete myPawn;
}

// Test for set_capture and get_if_captured
TEST_F(PieceTest, SetAndGetIfCaptured) {
    Piece* myPawn = new Pawn(1, 1, PlayerColor::White);
    EXPECT_FALSE(myPawn->get_if_captured());

    myPawn->set_capture(true);
    EXPECT_TRUE(myPawn->get_if_captured());

    myPawn->set_capture(false);
    EXPECT_FALSE(myPawn->get_if_captured());

    delete myPawn;
}

// Test for is_opponent_piece
TEST_F(PieceTest, IsOpponentPiece) {
    Piece* whitePawn = new Pawn(1, 1, PlayerColor::White);
    Piece* blackPawn = new Pawn(2, 2, PlayerColor::Black);
    Piece* whiteRook = new Rook(3, 3, PlayerColor::White);

    EXPECT_TRUE(whitePawn->is_opponent_piece(*blackPawn));
    EXPECT_FALSE(whitePawn->is_opponent_piece(*whiteRook));

    delete whitePawn;
    delete blackPawn;
    delete whiteRook;
}


TEST_F(PieceTest, InitialBoardNoneCanBeCaptured) {
    // This test is based on a standard initial chess board setup
    // which is the default for the Board class.
    // So we don't need to clear the board here.
    Board initialBoard;
    bool val = false;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 8; i++) {
            if(initialBoard.get_piece_at_pos(j,i) != nullptr) {
                val = val || (initialBoard.get_piece_at_pos(j, i)->can_be_captured(initialBoard));
            }
        }
    }
    for (int j = 6; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if(initialBoard.get_piece_at_pos(j,i) != nullptr) {
                val = val || (initialBoard.get_piece_at_pos(j, i)->can_be_captured(initialBoard));
            }
        }
    }
    EXPECT_FALSE(val);
}

// Test Case for Bishop Capture
TEST_F(PieceTest, PieceCapturedByBishop) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackBishop = new Bishop(1, 2, PlayerColor::Black);
    board.set_piece_at_pos(blackBishop, 1, 2);

    EXPECT_TRUE(whitePawn->can_be_captured(board));
    EXPECT_FALSE(blackBishop->can_be_captured(board));
}

TEST_F(PieceTest, PieceNotCapturedByBishop) {
    Piece* whitePawn = new Pawn(3, 3, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 3);
    Piece* blackBishop = new Bishop(1, 2, PlayerColor::Black);
    board.set_piece_at_pos(blackBishop, 1, 2);

    EXPECT_FALSE(whitePawn->can_be_captured(board));
}

// Test Case for King Capture
TEST_F(PieceTest, PieceCapturedByKing) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackKing = new King(4, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackKing, 4, 5);
  
    EXPECT_TRUE(whitePawn->can_be_captured(board));
    EXPECT_TRUE(blackKing->can_be_captured(board));
   
}

TEST_F(PieceTest, PieceNotCapturedByKing) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackKing = new King(5, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackKing, 5, 5);
    EXPECT_FALSE(whitePawn->can_be_captured(board));
}

// Test Case for Queen Capture
TEST_F(PieceTest, PieceCapturedByQueen) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackQueen = new Queen(3, 7, PlayerColor::Black);
    board.set_piece_at_pos(blackQueen, 3, 7);
    EXPECT_TRUE(whitePawn->can_be_captured(board));
    
    delete board.get_piece_at_pos(3,4);
    board.set_piece_at_pos(nullptr, 3, 4);
    
    delete board.get_piece_at_pos(3,7);
    board.set_piece_at_pos(nullptr, 3, 7);

    whitePawn = new Pawn(0, 7, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 0, 7);
    blackQueen = new Queen(3, 4, PlayerColor::Black);
    board.set_piece_at_pos(blackQueen, 3, 4);
    EXPECT_TRUE(whitePawn->can_be_captured(board));

    EXPECT_FALSE(blackQueen->can_be_captured(board));
}

TEST_F(PieceTest, PieceNotCapturedByQueen) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackQueen = new Queen(5, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackQueen, 5, 5);
    EXPECT_FALSE(whitePawn->can_be_captured(board));
}

// Test Case for Knight Capture
TEST_F(PieceTest, PieceCapturedByKnight) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackKnight = new Knight(5, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackKnight, 5, 5);
    EXPECT_TRUE(whitePawn->can_be_captured(board));
    EXPECT_FALSE(blackKnight->can_be_captured(board));
}

TEST_F(PieceTest, PieceNotCapturedByKnight) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackKnight = new Knight(5, 4, PlayerColor::Black);
    board.set_piece_at_pos(blackKnight, 5, 4);
    EXPECT_FALSE(whitePawn->can_be_captured(board));
}

// Test Case for Rook Capture
TEST_F(PieceTest, PieceCapturedByRook) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackRook = new Rook(3, 0, PlayerColor::Black);
    board.set_piece_at_pos(blackRook, 3, 0);
    EXPECT_TRUE(whitePawn->can_be_captured(board));
    EXPECT_FALSE(blackRook->can_be_captured(board));
}

TEST_F(PieceTest, PieceNotCapturedByRook) {
    Piece* whitePawn = new Pawn(3, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 4);
    Piece* blackRook = new Rook(2, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackRook, 2, 5);
    EXPECT_FALSE(whitePawn->can_be_captured(board));
}

// Test Cases for Pawn Capture
TEST_F(PieceTest, WhitePawnCanBeCapturedByBlackPawn) {
    Piece* whitePawn = new Pawn(4, 4, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 4, 4);
    Piece* blackPawn = new Pawn(5, 5, PlayerColor::Black);
    board.set_piece_at_pos(blackPawn, 5, 5);
   
    EXPECT_TRUE(whitePawn->can_be_captured(board));
    EXPECT_TRUE(blackPawn->can_be_captured(board));
}

TEST_F(PieceTest, BlackPawnCanBeCapturedByWhitePawn) {
    Piece* blackPawn = new Pawn(4, 4, PlayerColor::Black);
    board.set_piece_at_pos(blackPawn, 4, 4);
    Piece* whitePawn = new Pawn(3, 5, PlayerColor::White);
    board.set_piece_at_pos(whitePawn, 3, 5);
   
    EXPECT_TRUE(blackPawn->can_be_captured(board));
    EXPECT_TRUE(whitePawn->can_be_captured(board));
}

// Test Cases for Intervening Pieces
TEST_F(PieceTest, BlockedSlidingPieceCannotCapture) {
    Piece* whiteRook = new Rook(0, 0, PlayerColor::White);
    board.set_piece_at_pos(whiteRook, 0, 0);
    Piece* blockingPawn = new Pawn(0, 1, PlayerColor::White);
    board.set_piece_at_pos(blockingPawn, 0, 1);
    Piece* blackPawn = new Pawn(0, 2, PlayerColor::Black);
    board.set_piece_at_pos(blackPawn, 0, 2);

    EXPECT_FALSE(blackPawn->can_be_captured(board));
}

TEST_F(PieceTest, KnightCanJumpOverPiecesToCapture) {
    Piece* whiteRook = new Rook(0, 0, PlayerColor::White);
    board.set_piece_at_pos(whiteRook, 0, 0);
    Piece* blockingPawn = new Pawn(1, 0, PlayerColor::White);
    board.set_piece_at_pos(blockingPawn, 1, 0);
    Piece* blackKnight = new Knight(2, 1, PlayerColor::Black);
    board.set_piece_at_pos(blackKnight, 2, 1);

    EXPECT_TRUE(whiteRook->can_be_captured(board));
}

// Edge Case Test
TEST_F(PieceTest, PieceAtEdgeCanBeCaptured) {
    Piece* whiteKing = new King(0, 0, PlayerColor::White);
    board.set_piece_at_pos(whiteKing, 0, 0);
    Piece* blackRook = new Rook(0, 7, PlayerColor::Black);
    board.set_piece_at_pos(blackRook, 0, 7);

    EXPECT_TRUE(whiteKing->can_be_captured(board));
}