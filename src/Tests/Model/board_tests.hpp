#ifndef __BOARD_TESTS_HPP__
#define __BOARD_TESTS_HPP__

#include "../../Model/board.hpp"

TEST(BoardTests, BaseCase) {
    Board b;
    std::stringstream ss;
    std::string out = "RNBQKBNR\nPPPPPPPP\n        \n        \n        \n        \npppppppp\nrnbkqbnr\n";

    b.print(ss);

    EXPECT_EQ(ss.str(), out);
}

TEST(BoardTests, MoveTest) {
    Board* b = Board().move(coordinate(0,0), coordinate(3,5), 200);
    std::stringstream ss;
    b->print(ss);
    std::string out = " NBQKBNR\nPPPPPPPP\n        \n     R  \n        \n        \npppppppp\nrnbkqbnr\n";

    EXPECT_EQ(ss.str(), out);
}

TEST(BoardTests, PieceTest) {

}

TEST(BoardTests, PathTest) {

}

#endif