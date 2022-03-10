#include "../../Model/bishop.hpp"

TEST(BishopTests,WhiteMoveMid) {
        Board* b = Board().move(coordinate(7,2), coordinate(4,5),2 );
        Move* m1 = new Move(coordinate(4,5), coordinate(2,3));
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
        Move* m1 = new Move(coordinate(3,5), coordinate(1,3));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}
