#ifndef __PAWN_TEST_HPP__
#define __PAWN_TEST_HPP__

#include "../../Model/pawn.hpp"

TEST(PawnTests,IsValidMove1Empty) {
	Move m1(coordinate(6,1), coordinate(5,1));
	Board* b;
	Pawn test_piece;
	
	EXPECT_EQ(test_piece.IsMoveValid(m1,b),true );
}

#endif
