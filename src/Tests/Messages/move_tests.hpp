#ifndef __MOVE_TESTS_HPP__
#define __MOVE_TESTS_HPP__

#include "../../Messages/move.hpp"

TEST(MoveTest, BaseCase) {
    Move m1(new coordinate(1,1), new coordinate(3,2));
    EXPECT_TRUE(*m1.get_origin() == coordinate(1,1));
    EXPECT_TRUE(*m1.get_destination() == coordinate(3,2));

    Move m2(new coordinate(1,0), new coordinate(0,1));
    EXPECT_TRUE(*m2.get_origin() == coordinate(1,0));
    EXPECT_TRUE(*m2.get_destination() == coordinate(0,1));
    EXPECT_EQ(m2.info(), "Move from (1, 0) to (0, 1).\n");
}

TEST(MoveTest, DirectionBase) {
    Move m1(new coordinate(1,0), new coordinate(0,1));
    EXPECT_TRUE(m1.get_direction() == coordinate(-1,1));

    Move m2(new coordinate(8,8), new coordinate(1,1));
    EXPECT_TRUE(m2.get_direction() == coordinate(-1,-1));    

    Move m3(new coordinate(4,3), new coordinate(4,7));
    EXPECT_TRUE(m3.get_direction() == coordinate(0,1));

    Move m4(new coordinate(5,3), new coordinate(3,5));
    EXPECT_TRUE(m4.get_direction() == coordinate(-1,1));
}

TEST(MoveTest, DirectionKnight) {
    Move m1(new coordinate(1,0), new coordinate(2,2));
    EXPECT_TRUE(m1.get_direction() == coordinate(1,2));

    Move m2(new coordinate(8,8), new coordinate(6,7));
    EXPECT_TRUE(m2.get_direction() == coordinate(-2,-1));    

    Move m3(new coordinate(4,3), new coordinate(2,4));
    EXPECT_TRUE(m3.get_direction() == coordinate(-2,1));

    Move m4(new coordinate(5,3), new coordinate(3,7));
    EXPECT_TRUE(m4.get_direction() == coordinate(-1,2));
}

TEST(MoveTest, DirectionFloats) {
    Move m1(new coordinate(3,4), new coordinate(100,100));
    EXPECT_TRUE(m1.get_direction() == coordinate(1,1));

    Move m2(new coordinate(1,2), new coordinate(4,12));
    EXPECT_TRUE(m2.get_direction() == coordinate(1,3));    

    Move m3(new coordinate(4,3), new coordinate(4,7));
    EXPECT_TRUE(m3.get_direction() == coordinate(0,1));

    Move m4(new coordinate(5,3), new coordinate(3,5));
    EXPECT_TRUE(m4.get_direction() == coordinate(-1,1));
}

TEST(MoveTest, DirectionComplex) {
    // no move
    Move m1(new coordinate(1,0), new coordinate(1,0));
    EXPECT_TRUE(m1.get_direction() == coordinate(-1,1));

    Move m2(new coordinate(-8,8), new coordinate(8,-8));
    EXPECT_TRUE(m2.get_direction() == coordinate(1,-1));    

    Move m3(new coordinate(12,12), new coordinate(3,1));
    EXPECT_TRUE(m3.get_direction() == coordinate(-1,1));

    Move m4(new coordinate(12233,785131415), new coordinate(0,333333));
    EXPECT_TRUE(m4.get_direction() == coordinate(0,0));    
}

#endif
