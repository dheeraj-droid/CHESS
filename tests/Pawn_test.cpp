#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Board.hpp"
#include "Pawn.hpp"
#include "Rook.hpp" 


using ::testing::UnorderedElementsAre;

class PawnTest : public ::testing::Test {
protected:
    Board board;
};

//  Verifies a white pawn's initial two-square move option.
TEST_F(PawnTest, WhitePawnInitialMove) {
    Piece* pawn = board.get_piece_at_pos(1, 4); 
    auto moves = pawn->get_valid_moves(board);

    
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4),
        std::make_pair(3, 4)
    ));
}

//  Verifies a black pawn's initial two-square move option.
TEST_F(PawnTest, BlackPawnInitialMove) {
    Piece* pawn = board.get_piece_at_pos(6, 4); 
    auto moves = pawn->get_valid_moves(board);

    
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(5, 4),
        std::make_pair(4, 4)
    ));
}

// Verifies a pawn can only move one square forward initially if the second square is blocked by opponent.
TEST_F(PawnTest,PawnInitialMoveSecondBlockedSqaureOpponentPiece)
{
    Piece* pawn = board.get_piece_at_pos(1, 4); 
    board.set_piece_at_pos(new Rook(3, 4, PlayerColor::Black), 3, 4);
    auto moves = pawn->get_valid_moves(board);

   
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4)
    ));
}

// Verifies a pawn can only move one square forward initially if the second square is blocked by same color piece.
TEST_F(PawnTest,PawnInitialMoveSecondBlockedSqaureFriendlyPiece)
{
    Piece* pawn = board.get_piece_at_pos(1, 4); 
    board.set_piece_at_pos(new Rook(3, 4, PlayerColor::White), 3, 4);
    auto moves = pawn->get_valid_moves(board);

   
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4)
    ));
}

// Verifies a pawn can only move one square forward after its initial move.
TEST_F(PawnTest, PawnSingleMoveAfterMoved) {
    Piece* pawn = board.get_piece_at_pos(1, 4); 
    pawn->set_if_moved(true); 
    auto moves = pawn->get_valid_moves(board);

   
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4)
    ));
}

//  Verifies that a pawn has no forward moves if it's blocked.
TEST_F(PawnTest, PawnBlocked) {
   
    board.set_piece_at_pos(new Rook(2, 4, PlayerColor::Black), 2, 4);
    Piece* pawn = board.get_piece_at_pos(1, 4);
    auto moves = pawn->get_valid_moves(board);

    
    EXPECT_TRUE(moves.empty());
}

//  Verifies a pawn can move forward and capture diagonally.
TEST_F(PawnTest, PawnCanCapture) {
   
    board.set_piece_at_pos(new Rook(2, 3, PlayerColor::Black), 2, 3);
    board.set_piece_at_pos(new Rook(2, 5, PlayerColor::Black), 2, 5);
    Piece* pawn = board.get_piece_at_pos(1, 4);
    auto moves = pawn->get_valid_moves(board);

    
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4), 
        std::make_pair(3, 4), 
        std::make_pair(2, 3), 
        std::make_pair(2, 5)  
    ));
}

//  Verifies a pawn cannot capture a friendly piece.
TEST_F(PawnTest, PawnCannotCaptureFriendlyPiece) {
    
    board.set_piece_at_pos(new Rook(2, 3,  PlayerColor::White), 2, 3);
    Piece* pawn = board.get_piece_at_pos(1, 4);
    auto moves = pawn->get_valid_moves(board);

    
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4),
        std::make_pair(3, 4)
    ));
}

//  Verifies capture logic for a pawn on the edge of the board (A-file).
TEST_F(PawnTest, PawnOnEdgeCanCapture) {
   
    board.set_piece_at_pos(new Rook(2, 1, PlayerColor::Black), 2, 1);
    Piece* pawn = board.get_piece_at_pos(1, 0);
    auto moves = pawn->get_valid_moves(board);

  
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 0), 
        std::make_pair(3, 0), 
        std::make_pair(2, 1) 
    ));
}

