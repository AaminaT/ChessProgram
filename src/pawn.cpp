#include "pawn.hpp"

using namespace std;

bool Pawn::IsMoveValid(Move move,Board* board)
{
	bool validMove = true;
	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();

	int distance = 0; // squares between orig and dest

	// - clear path check -
	// 1. <--> movement is not allowed
	if (orig.row == dest.row)
	{
		return false;
	}
	// 2. same column - can move 1 if nothing directly infront
	if (orig.col == dest.col)
	{
		distance = (orig.row < dest.row ? (dest.row - orig.row) - 1 : (orig.row - dest.row) - 1);
		if (distance >= 0 || !(board->at(dest.row, dest.col) != ' '))
			return false;
	}
	// for two space move, program will check 1 space ahead first
	// 3. same column - can move 2 steps when at row 1 or 6 (rows: [0-7]) if nothing directly infront
	if (orig.col == dest.col)
	{
		distance = (orig.row < dest.row ? (dest.row - orig.row) - 2 : (orig.row - dest.row) - 2);
		if (distance != 0 || !(board->at(dest.row, dest.col) != ' '))
			return false;
	}
	// 4. diagonals - when pawn has another piece in that adajacent diagonal
	if (orig.row != dest.row && orig.col != dest.col)
	{
		int distanceRow = (orig.row < dest.row ? (dest.row - orig.row) - 1 : (orig.row - dest.row) - 1);
		int distanceCol = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
		if ((distanceRow != 0 && distanceCol != 0) || !(board->at(dest.row, dest.col) == ' '))
			return false;
	}
	return validMove;
}

int Pawn::int getValue() {
	return 0;
}

list<coordinate>* Pawn::getDirections() {
	list<coordinate>* ls;

	return ls;
}

