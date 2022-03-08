#ifndef UpdateBoard_hpp
#define UpdateBoard_hpp

#include <stdio.h>
#include "board.hpp"
#include "board.cpp"

class UpdateBoard:public Board{
    private:
    	Board* Board;
    public:
        char* getUIBoard();
        class Board getBoard();
};

#endif /* UpdateBoard_hpp */
