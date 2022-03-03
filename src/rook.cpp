#include "rook.hpp"

using namespace std;

bool Rook::isMoveValid(Move* move, const Board* board)
{
	bool validMove = true;
	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();

	int distance = 0; // squares between orig and dest

	// - clear path check -
  	// cases: moves occuring in 
  	// 1. same row 
 	// 2. same column 
	if (orig.row == dest.row){ 
		distance = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
		while (distance != 0)
		{
			if (orig.col < dest.col)
				++orig.col;
			else
				--orig.col;

			if (!(board->at(orig.row, orig.col) == ' '))
				return false;

			--distance;
		}
	}
	else if (orig.col == dest.col) {
		distance = (orig.row < dest.row ? (dest.row - orig.row) - 1 : (orig.row - dest.row) - 1);
		while (distance != 0)
		{
			if (orig.row < dest.row)
				++orig.row;
			else
				--orig.row;

			if (!(board->at(orig.row, orig.col) == ' '))
				return false;

			--distance;
		}
	}
	else {
		return false;
	}
	return validMove;
}

list<coordinate>* Rook::getDirections(Board* board)
{
	list<coordinate>* ls;

	return ls;
}
