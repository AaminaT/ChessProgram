#ifndef __BOARD_HPP__
#define __BOARD_HPP__

class Board {
    private:
        char* board;
        int value;
        int depth;

    public:
        Board(): board{new char*[65]} {
            std::string order = "RNBKQBNRPPPPPPPP";
            for(int i = 0; i < 64; ++i) {
                board[i] = (1 < i/8 && i/8 < 6? ' ': (i/16 == 0? order[i]: order[15 - i%16] + 32))
            board[64] = '\0';
        }
        
        Board(Board& other): board{new char*[65]} {
            for(int i = 0; i < 65; ++i)
                this->board[i] = other.board[i];
        }

        char& at(int row, int col) {return board[row*8 + col];}

        void set(int row, int col, char val) {}

        int get_value()

        ~Board() {delete[] board;}
};

#endif
