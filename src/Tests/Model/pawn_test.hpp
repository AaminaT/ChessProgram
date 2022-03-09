#ifndef __PAWN_TEST_HPP__
#define __PAWN_TEST_HPP__

#include "../../Model/pawn.hpp"

TEST(PawnTests,WhiteMove1Empty) {
	Board* b = new Board();
	Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
	Pawn test_piece;
	
	EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
	delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove2Empty) {
        Board* b = new Board(); 
        Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(PawnTests,BlackMove1Empty) {
        Board* b = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
	Move* m2 = new Move(coordinate(1,1), coordinate(2,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b),true);
        delete b;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove2Empty) {
        Board* b = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
	Move* m2 = new Move(coordinate(1,1), coordinate(3,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b),true);
        delete b;
        delete m1;
        delete m2;
}

TEST(PawnTests,CaptureWithPawn) {
	// move diagonal
        Board* b1 = Board().move(coordinate(3,6), coordinate(3,7) , 1);
        Board* b2 = Board().move(coordinate(3,6), coordinate(3,7) , 1);
	Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
        Move* m2 = new Move(coordinate(1,2), coordinate(3,2));
	Move* m3 = new Move(coordinate(4,1), coordinate(3,2));
	
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b2),true);
	delete b1;
        delete b2;
        delete m1;
        delete m2;
}

#endif
