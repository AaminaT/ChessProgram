#include "../../Model/bishop.hpp"

TEST(BishopTests,WhiteMoveMid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(4,5), coordinate(2,4));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(BishopTests,WhiteMoveMidWrong) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(7,5), coordinate(6,5));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(BishopTests,WhiteMoveMid2) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(2,5), coordinate(0,3));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}
