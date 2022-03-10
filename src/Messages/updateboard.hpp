#ifndef __UPDATE_BOARD_HPP__
#define __UPDATE_BOARD_HPP__

#include "message.hpp"
#include "../Model/board.hpp"

class UpdateBoard: public Message {
    private:
        Board* board;

    public:
};

#endif