#include "king.hpp"

using namespace std;

bool King::isMoveValid(Move* move, const Board* board)
{
	bool validMove = true;
	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();

	int distance = 0; // squares between orig and dest

	// - clear path check -
	// cases: moves occuring in
 	// 1. same row
 	// 2. same column
 	// 3. diagonals */
	if (orig.row == dest.row) {
		distance = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
		if (distance != 0 || !(board->at(dest.row, dest.col) == ' '))
			return false;

	}
	else if (orig.col == dest.col) {
		distance = (orig.row < dest.row ? (dest.row - orig.row) - 1 : (orig.row - dest.row) - 1);
		if (distance != 0 || !(board->at(dest.row, dest.col) == ' '))
			return false;
	}
	else {
		int distanceRow = (orig.row < dest.row ? (dest.row - orig.row) - 1 : (orig.row - dest.row) - 1);
		int distanceCol = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
		if ((distanceRow != 0 && distanceCol != 0) || !(board->at(dest.row, dest.col) == ' '))
			return false;
	}
	return validMove;
}

list<coordinate>* King::getDirections(Board* board)
{
	list<coordinate>* ls;

	return ls;
}
