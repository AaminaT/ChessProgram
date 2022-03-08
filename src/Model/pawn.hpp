#include "piece.hpp"

class Pawn : public Piece {
	public:
		bool IsMoveValid(Move move,Board* board);

}
