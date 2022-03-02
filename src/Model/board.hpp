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
    class piece_iterator;
    class path_iterator;
    
    Board(): board{new char[65]}, value{0}, depth{0} {
        std::string order = "RNBKQBNRPPPPPPPP";
        for(int i = 0; i < 64; ++i)
            board[i] = (1 < i/8 && i/8 < 6? ' ': (i/16 == 0? order[i]: order[15 - i%16] + 32));
        board[64] = '\0';
    }

    Board(const Board& other): board{new char[65]}, value{other.value}, depth{other.depth} {
        for(int i = 0; i < 65; ++i)
            this->board[i] = other.board[i];
    }

    Board(Board&& other): board{other.board}, value{other.value}, depth{other.depth} { other.board = nullptr; }
    ~Board() { delete[] board; }
    
    // at: get piece at a specific position on the board
    char at(int x) const { return board[x]; }
    char at(int row, int col) const { return at(row*8 + col); }
    piece_info at(coordinate& pos) const { return piece_info(new coordinate(pos), at(pos.row, pos.col), side(pos.row, pos.col)); }

    // 
    Board* move(coordinate& origin, coordinate& destination, int piece_value) {
        Board* b = new Board(*this);

        b->board[destination.row*8 + destination.col] = at(origin.row, origin.col);
        ++b->depth;
        b->value += piece_value*side(origin.row, origin.col);

        return b;
    }
    
    // side: get the side associated with a piece at a specified position
    int side(int x) const { return at(x) == ' '? 0: at(x) >= 'a'? 1: -1; }
    int side(int row, int col) const { return side(row*8 + col); }

    // get_value: 
    int get_value() const { return value + (value < 0? 1: -1)*depth; }

    void print(std::ostream& out) {
        for(int i = 0; i < 64; i++) {    
            out << board[i];
            if(i%8 == 7)
                out << std::endl;
        }
    }
    
    piece_iterator begin() { return piece_iterator(this); }
    piece_iterator end() { return piece_iterator(this, 64); }
    path_iterator begin(coordinate& start, coordinate& dir) { return path_iterator(this, start, dir); }
    path_iterator end(coordinate& end, coordinate& dir) { return ++path_iterator(this, end, dir); }

    class piece_info {
        private:
            coordinate* _pos;
            char _piece;
            int _side;

        public:
            piece_info(coordinate* pos, char piece, int side): _pos{pos}, _piece{piece}, _side{side} {}
            piece_info(piece_info&& other): _pos{other._pos}, _piece{other._piece}, _side{other._side} {other._pos == nullptr;}
            ~piece_info() {delete _pos;}

            coordinate pos() { return *_pos; }
            char piece() { return _piece; }
            int side() { return _side; }
            bool hasPiece() { return _side != 0; }
            bool isWhite() { return _side == 1; }
    };

    class piece_iterator {
        private:
            Board* board;
            int pos;

        public:
            piece_iterator(Board* b, int x = 0): board{b}, pos{x} {}

            piece_iterator& operator++() {
                if(board->at(pos) != '\0')
                    ++pos;
                while(board->at(pos) == ' ')
                    ++pos;

                return *this;
            }

            piece_iterator operator++(int) {
                piece_iterator temp = *this;
                ++(*this);
                return temp;
            }

            piece_info operator*() {
                if(pos >= 64)
                    throw "iterator out of bounds!";
                
                return piece_info(new coordinate(pos/8, pos%8), board->at(pos), board->side(pos));
            }
            
            bool operator==(const piece_iterator& other) { return this->pos == other.pos; }
            bool operator!=(const piece_iterator& other) { return !(*this == other); }
    };

    class path_iterator {
        private:
            Board* board;
            coordinate* current;
            coordinate& origin;
            coordinate& dir;

        public:
            path_iterator(Board* b, coordinate& o, coordinate& d): board{b}, current{new coordinate(o)}, origin{o}, dir{d} {}
            ~path_iterator() { delete current; }

            path_iterator& operator++() {
                *current = *current + dir;
                return *this;
            }

            path_iterator operator++(int) {
                path_iterator temp = *this;
                ++(*this);
                return temp;
            }

            piece_info operator*() {
                if(current->row < 0 || current->row > 7 || current->col < 0 || current->col > 7)
                    throw "iterator out of bounds!";
                
                return board->at(*current);
            }
            
            bool operator==(const path_iterator& other) { return this->current == other.current; }
            bool operator!=(const path_iterator& other) { return !(*this == other); }
    }
};

#endif
