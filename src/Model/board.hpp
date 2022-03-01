#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include "coordinate.hpp"

class Board {
private:
    char* board;
    int value;
    int depth;

public:
    class piece_info;
    class board_iterator;
    
    Board(): board{new char[65]}, value{0}, depth{0} {
        std::string order = "RNBKQBNRPPPPPPPP";
        for(int i = 0; i < 64; ++i)
            board[i] = (1 < i/8 && i/8 < 6? ' ': (i/16 == 0? order[i]: order[15 - i%16] + 32));
        board[64] = '\0';
    }

    Board(Board& other): board{new char[65]}, value{other.value}, depth{other.depth} {
        for(int i = 0; i < 65; ++i)
            this->board[i] = other.board[i];
    }

    Board(Board&& other): board{other.board}, value{other.value}, depth{other.depth} { other.board = nullptr; }
    ~Board() { delete[] board; }
    

    char at(int x) const { return board[x]; }
    char at(int row, int col) const { return at(row*8 + col); }
    piece_info at(coordinate& pos) const { return piece_info(new coordinate(pos), at(pos.row, pos.col), side(pos.row, pos.col)); }

    void move(coordinate& origin, coordinate& destination, int piece_value) {
        board[destination.row*8 + destination.col] = at(origin.row, origin.col);
        depth++;
        value += piece_value*side(origin.row, origin.col);
    }
    
    int side(int x) const { return at(x) == ' '? 0: at(x) >= 'a'? 1: -1; }
    int side(int row, int col) const { return side(row*8 + col); }
    int get_value() const { return value + (value < 0? 1: -1)*depth; }

    void print(std::ostream& out) {
        for(int i = 0; i < 64; i++) {    
            out << board[i];
            if(i%8 == 7)
                out << std::endl;
        }
    }
    
    board_iterator begin() { return board_iterator(this); }
    board_iterator end() { return board_iterator(this, 65); }

    class piece_info {
        private:
            coordinate* pos;
            char piece;
            int side;

        public:
            piece_info(coordinate* pos, char piece, int side): pos{pos}, piece{piece}, side{side} {}
            piece_info(piece_info&& other): pos{other.pos}, piece{other.piece}, side{other.side} {other.pos == nullptr;}
            ~piece_info() {delete pos;}

            coordinate pos() { return *pos; }
            char piece() { return piece; }
            int side() { return side; }
            bool hasPiece() { return side != 0; }
            bool isWhite() { return side == 1; }
    };

    class board_iterator {
        private:
            Board* board;
            int pos;

        public:
            board_iterator(Board* b, int x = 0): board{b}, pos{x} {}

            board_iterator& operator++() {
                if(board->at(pos) != '\0')
                    ++pos;
                while(board->at(pos) == ' ')
                    ++pos;
            }

            board_iterator operator++(int) {
                board_iterator temp = *this;
                ++(*this);
                return temp;
            }

            piece_info operator*() {
                if(pos == 64)
                    throw "can not dereference end iterator";
                
                return piece_info(new coordinate(pos/8, pos%8), board->at(pos), board->side(pos));
            }
            
            bool operator==(const board_iterator& other) { return this->pos == other.pos; }
            bool operator!=(const board_iterator& other) { return !(*this == other); }
    };

    
};

#endif
