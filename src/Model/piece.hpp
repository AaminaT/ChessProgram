#ifndef __PIECE_HPP__
#define __PIECE_HPP__

class Piece {
    public:
        virtual bool isMoveValid(Move*, Board*) = 0;
};

#endif
