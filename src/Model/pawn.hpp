#include "piece.hpp"

using namespace std;

class Pawn : public Piece {
	public:
		bool isMoveValid(Move* move,Board* board)
		{
			bool validMove = false;
			
			coordinate orig = move->get_origin();
			coordinate dest = move->get_destination();
			
			int distance = move->get_distance();
			coordinate direction = move->get_direction();
			
			int number_turn = board->get_turn();
			
			auto moving_piece = board->at(move->get_origin());
			auto targeted_piece = board->at(move->get_destination());
			
			int p = number_turn%2 == 0? -1: 1;
			
			if(distance < 3 && are_equivalent(coordinate(1,0) * p, direction))
			{
				if(distance == 2 && orig.row == (moving_piece.isWhite()? 6: 1))
				{
					auto it = board->path_begin(*move);
					it++;
					bool has = true;
					for(it; it != board->path_end(); it++)
					{
						if((*it).hasPiece())
						{
							has = false;
							break;
						}
					}
					return has;
				}
				else if(distance == 1)
				{
					auto it = board->path_begin(*move);
					it++;
					bool has = true;
					if((*it).hasPiece())
						has = false;
					return has;
				}
			}
			
			if(distance == 1 && are_equivalent(coordinate(1,1) * p, direction) && targeted_piece.side() != moving_piece.side())
    				return true;
			if(distance == 1 && are_equivalent(coordinate(-1,1) * p, direction) && targeted_piece.side() != moving_piece.side())
				return true;	
			return validMove;
		};
};
