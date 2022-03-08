#include <stdio.h>
#pragma once
//pragma used as a gnu/c++ compiler
#include <iostream>
#include <cmath>
#include <string>

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

class Square{
    Piece piece;
    Color color;
//const int depth;
int x, y;
    public:
    	void setSpace(Square*);
    	void setEmpty();
    	void setPieceAndColor(Piece, Color);
    	Piece getPiece();
    	Color getColor();
    	void setX(int ex) { x = ex; }
    	void setY(int why) { y = why; }
    	int getX() { return x; }
    	int getY() { return y; }
 	Square();
};

class Board{
    Square square[8][8];
    Color turn=WHITE;
    void printBoard();
    public:
        Square* getSquare(int x, int y) {
            return &square[x][y];
        }
        void setSquare(Square * s, int x, int y){
            square[x][y]=*s;
        }
 
};
