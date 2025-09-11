#include "../third_party/googletest/googletest/include/gtest/gtest.h"
#include "../third_party/googletest/googlemock/include/gmock/gmock.h"
#include "../src/Board.hpp"
#include "../src/Pawn.hpp"
#include "../src/Rook.hpp" // Using Rook as a generic piece for blocking/capturing

// Using a matcher from gmock to compare move lists irrespective of order
using ::testing::UnorderedElementsAre;

class PawnTest : public ::testing::Test {
protected:
    
    Board board;
};

// Test 1: Verifies a white pawn's initial two-square move option.
TEST_F(PawnTest, WhitePawnInitialMove) {
    Piece* pawn = board.get_piece_at_pos(1, 4); // White e2 pawn
    auto moves = pawn->get_valid_moves(board);

    // Expect moves to e3 (2,4) and e4 (3,4)
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4),
        std::make_pair(3, 4)
    ));
}

// Test 2: Verifies a black pawn's initial two-square move option.
TEST_F(PawnTest, BlackPawnInitialMove) {
    Piece* pawn = board.get_piece_at_pos(6, 4); // Black e7 pawn
    auto moves = pawn->get_valid_moves(board);

    // Expect moves to e6 (5,4) and e5 (4,4)
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(5, 4),
        std::make_pair(4, 4)
    ));
}

// Test 3: Verifies a pawn can only move one square forward after its initial move.
TEST_F(PawnTest, PawnSingleMoveAfterMoved) {
    Piece* pawn = board.get_piece_at_pos(1, 4); // White e2 pawn
    pawn->set_if_moved(true); // Manually mark the pawn as having moved
    auto moves = pawn->get_valid_moves(board);

    // Expect only a single move to e3 (2,4)
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4)
    ));
}

// Test 4: Verifies that a pawn has no forward moves if it's blocked.
TEST_F(PawnTest, PawnBlocked) {
    // Place a piece at e3, blocking the e2 pawn
    board.set_piece_at_pos(new Rook(2, 4, "black"), 2, 4);
    Piece* pawn = board.get_piece_at_pos(1, 4);
    auto moves = pawn->get_valid_moves(board);

    // The pawn is blocked, so it should have no valid moves.
    EXPECT_TRUE(moves.empty());
}

// Test 5: Verifies a pawn can move forward and capture diagonally.
TEST_F(PawnTest, PawnCanCapture) {
    // Place black pieces at d3 and f3 for the e2 pawn to capture
    board.set_piece_at_pos(new Rook(2, 3, "black"), 2, 3); // d3
    board.set_piece_at_pos(new Rook(2, 5, "black"), 2, 5); // f3
    Piece* pawn = board.get_piece_at_pos(1, 4); // e2 pawn
    auto moves = pawn->get_valid_moves(board);

    // Expect forward moves to e3, e4 and capture moves to d3, f3
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4), // move to e3
        std::make_pair(3, 4), // move to e4
        std::make_pair(2, 3), // capture at d3
        std::make_pair(2, 5)  // capture at f3
    ));
}

// Test 6: Verifies a pawn cannot capture a friendly piece.
TEST_F(PawnTest, PawnCannotCaptureFriendlyPiece) {
    // Place a friendly (white) piece at d3
    board.set_piece_at_pos(new Rook(2, 3, "white"), 2, 3);
    Piece* pawn = board.get_piece_at_pos(1, 4); // e2 pawn
    auto moves = pawn->get_valid_moves(board);

    // Expect only the forward moves, not the capture on d3
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 4),
        std::make_pair(3, 4)
    ));
}

// Test 7: Verifies capture logic for a pawn on the edge of the board (A-file).
TEST_F(PawnTest, PawnOnEdgeCanCapture) {
    // Place a black piece on b3 for the a2 pawn to capture
    board.set_piece_at_pos(new Rook(2, 1, "black"), 2, 1);
    Piece* pawn = board.get_piece_at_pos(1, 0); // a2 pawn
    auto moves = pawn->get_valid_moves(board);

    // Expect forward moves to a3, a4 and one capture move to b3
    EXPECT_THAT(moves, UnorderedElementsAre(
        std::make_pair(2, 0), // move to a3
        std::make_pair(3, 0), // move to a4
        std::make_pair(2, 1)  // capture at b3
    ));
}