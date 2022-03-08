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
    Board* b1 = Board().move(coordinate(0,0), coordinate(3,5), 0);
    Board* b2 = b1->move(coordinate(7,7), coordinate(3,5), 200);
    std::string out1 = " NBQKBNR\nPPPPPPPP\n        \n     R  \n        \n        \npppppppp\nrnbkqbnr\n";
    std::string out2 = " NBQKBNR\nPPPPPPPP\n        \n     r  \n        \n        \npppppppp\nrnbkqbn \n";
    std::stringstream ss;
    
    b1->print(ss);
    EXPECT_EQ(ss.str(), out1);
    EXPECT_EQ(b1->get_value(), 0);
    
    b2->print(ss);
    EXPECT_EQ(ss.str(), out2);
    EXPECT_EQ(b2->get_value(), 200);
}

TEST(BoardTests, PieceIteratorTest) {
    Board* b = new Board();
    std::stringstream ss;
    std::string out1 = "RNBQKBNRPPPPPPPPpppppppprnbkqbnr";

    int i = 0;
    for(auto it = b->piece_begin(); it != b->piece_end(); it++) {
        ASSERT_EQ((*it).piece(), out1[i]);
        ASSERT_EQ((*it).pos().stringify(), coordinate(i/8 + (i < 16? 0: 4), i%8).stringify());
        ASSERT_EQ((*it).isWhite(), i > 15);
        i++;
    }
    EXPECT_EQ(i, 32);

    delete b;
    std::string out2 = "RNBKBNRPPPPPPPPpppppQpprnbkqbnr";
    b = Board().move(coordinate(0,3), coordinate(6,5), 200);
    
    coordinate* c = nullptr;
    for(auto it = b->piece_begin(); it != b->piece_end(); it++) {
        ASSERT_EQ((*it).piece(), out2[i]);
        i++;
    }
    EXPECT_NE(i, 32);
}

TEST(BoardTests, PathIteratorTest) {

}

#endif