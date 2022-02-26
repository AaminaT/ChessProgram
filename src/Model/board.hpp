#ifndef __BOARD_HPP__
#define __BOARD_HPP__

class Board {
    private:
        char* board;
        int value;
        int depth;

    public:
        class piece_info {
            private:
                int row;
                int col;
                char piece;
                int side;

            public:
                piece_info() {}
                piece_info(piece_info&& other) {}

                int row() {return row;}
                int col() {return col;}
                char piece() {return piece;}
                int side() {return side;}

                void operator=(piece_info&& other) {}
        }

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

        piece_info&& at(int row, int col) const {}

        char at(int row, int col) const {return board[row*8 + col];}

        int side(int row, int col) const {
            int _side;
            char piece = at(row, col);

            if(piece == ' ')
                _side = 0;
            else
                _side = 'a' <= piece && piece <= 'z'? 1: 2;

            return _side;
        }

        void set(int row, int col, char val) {
            if(is_white(row,col))
        }

        int get_value()

        ~Board() {delete[] board;}

        board_iterator&& begin() {}
        board_iterator&& end() {}

        class board_iterator {
            private:
                int pos;

            public:
                board_iterator(int x = 0) pos{x} {}
                void operator++() {
                    if(board[x] != '\0')
                        ++x;
                    while(board[x] == ' ')
                        ++x;
                }

                char operator*() {}
                int get_x() {}
                int get_y() {}
                int get_side() {}

                bool operator==(const board_iterator& other) {return this->pos == other.pos;}
        };
};

#endif
