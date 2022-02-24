#include "board.hpp"

Square::Square(){
    piece = EMPTY;
    color = NONE;
}
void Square::setSpace(Square* space){
    color = space->getColor();
    piece = space->getPiece();
}
void Square::setEmpty(){
    color = NONE;
    piece = EMPTY;
}

Piece Square::getPiece(){
    return piece;
}

Color Square::getColor(){
    return color;
}
void Square::setPieceAndColor(Piece p, Color c){
    piece = p;
    color = c;
}

void Board::printBoard() {
    using namespace std;
    cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
    for (int i = 0; i < 8; i++){
        cout << " " << i << "   ";
        for (int n = 0; n < 8; n++){
            Piece p = square[i][n].getPiece();
            Color c = square[i][n].getColor();
            switch (p){
            case KING: (c == WHITE) ? cout << " K " : cout << " k ";
                break;
            case QUEEN: (c == WHITE) ? cout << " Q " : cout << " q ";
                break;
            case BISHOP:(c == WHITE) ? cout << " B " : cout << " b ";
                break;
            case KNIGHT:(c == WHITE) ? cout << " H " : cout << " h ";
                break;
            case ROOK: (c == WHITE) ? cout << " R " : cout << " r ";
                break;
            case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";
                break;
            case EMPTY: cout << " " << "\21" << " ";
                break;
            default: cout << "X";
                break;
            }
        }
        cout << endl;
    }
}

void Board::setBoard()
{
    square[0][0].setPieceAndColor(ROOK, WHITE);
    square[1][0].setPieceAndColor(KNIGHT, WHITE);
    square[2][0].setPieceAndColor(BISHOP, WHITE);
    square[3][0].setPieceAndColor(QUEEN, WHITE);
    square[4][0].setPieceAndColor(KING, WHITE);
    square[5][0].setPieceAndColor(BISHOP, WHITE);
    square[6][0].setPieceAndColor(KNIGHT, WHITE);
    square[7][0].setPieceAndColor(ROOK, WHITE);

    square[0][7].setPieceAndColor(ROOK, BLACK);
    square[1][7].setPieceAndColor(KNIGHT, BLACK);
    square[2][7].setPieceAndColor(BISHOP, BLACK);
    square[3][7].setPieceAndColor(QUEEN, BLACK);
    square[4][7].setPieceAndColor(KING, BLACK);
    square[5][7].setPieceAndColor(BISHOP, BLACK);
    square[6][7].setPieceAndColor(KNIGHT, BLACK);
    square[7][7].setPieceAndColor(ROOK, BLACK);

    for (int i = 0; i < 8; i++)
    {
        square[i][1].setPieceAndColor(PAWN, WHITE);
        square[i][6].setPieceAndColor(PAWN, BLACK);

    }
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
            square[j][i].setPieceAndColor(EMPTY, NONE);

    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            square[i][j].setX(i);
            square[i][j].setY(j);
        }

}
