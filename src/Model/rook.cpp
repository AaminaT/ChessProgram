#include "rook.hpp"

using namespace std;

bool Rook::isMoveValid(Move* move, Board* board)
{
	bool validMove = true;

	coordinate dir = move->get_direction();

	// clear path check for both vertical and horizontal paths
	// * only need to check for one coordinate direction (->) since paths expand in both directions (<->)
	if (are_equivalent(coordinate(1, 0), dir) || are_equivalent(coordinate(0, 1), dir)) {
		Board::path_iterator it = board->path_begin(*move);
		while (it != board->path_end()) {
			++it;
			if ((*it).hasPiece())
				return false;
		}
	}
	else {
		return false;
	}

	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();

	// if path is clear, check if there is a piece on landing coordinate
	if (board->at(dest).piece() != ' ') {
		// if there is a piece on landing coordinate, check if it's capturable
		if (board->at(orig).side() == board->at(dest).side()) {
			return false;
		}
	}
	return validMove;
}
