#include "../../Model/knight.hpp"

TEST(KnightTests,WhiteMove) {
        Board* b = Board().move(coordinate(6,7), coordinate(5,5),2 );
        Move* m1 = new Move(coordinate(5,5), coordinate(6,3));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(KnightTests,WhiteMoveInvalid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(1,7), coordinate(1,5));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(KnightTests,WhiteMoveMidInvalid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(2,5), coordinate(4,4));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}
