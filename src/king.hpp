#include "piece.hpp"

class King : public Piece {
	private:
		Move move;
		Board* board;
		list<coordinate> List;
	public:
		bool IsMoveValid(Move move,Board* board);
		int getValue();
		list getDirections()

}
