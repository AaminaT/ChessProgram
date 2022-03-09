#include "piece.hpp"

using namespace std;

class Pawn : public Piece {
	public:
		bool IsMoveValid(Move move,Board* board)
		{
			bool validMove = true;
			
			coordinate orig = move.get_origin();
			coordinate dest = move.get_destination();
			
			int distance = move.get_distance();
			
			int number_turn = board->get_turn();
			
			auto moving_piece = board->at(move->get_origin());
			auto targeted_piece = board->at(move->get_destination());
			
			//row 1 starting position
			if (number_turn % 2 == 0) //even turn = black piece
			{
				// 1. <--> movement is not allowed
				if (orig.row == dest.row)
				{
					return false;
				}
				// 2. up movement is not allowed
				if (orig.row > dest.row)
				{
					return false;
				}
				// 3. same column - can move 1 if nothing directly infront
 				if (orig.col == dest.col)
				{
					//orig.row < dest.row
					if (distance < 1  || board->at(dest) != ' ')
						return false;
				}
				// for two space move, program will check 1 space ahead first
				// 4. same column - can move 2 steps when at row 1 (rows: [0-7]) if nothing directly infront
				if (orig.col == dest.col)
				{
					if (distance > 2 || board->at(dest) != ' ' || orig.row != 1)
						return false;
				}
				// 5. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront and same team
				if( ( are_dependent(coordinate(1,1), move->get_direction()) || are_dependent(coordinate(-1,1), move->get_direction()) ) )
				{
					if(distance != 1 && targeted_piece.side() == moving_piece.side())
						return false;
				}
				// 6. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront and opposite team
				if( ( are_dependent(coordinate(1,1), move->get_direction()) || are_dependent(coordinate(-1,1), move->get_direction()) ) )
				{
					if(distance == 1 && targeted_piece.side() != moving_piece.side())
						return validMove;
				}
			}
			//row 6 starting position
			else //odd turn = white piece
			{
				// 1. <--> movement is not allowed
				if (orig.row == dest.row)
				{
					return false;
				}
				// 2. down movement is not allowed
				if (orig.row < dest.row)
				{
					return false;
				}
				// 3. same column - can move 1 if nothing directly infront
				if (orig.col == dest.col)
				{
					//orig.row > dest.row
					if (distance > -1 || board->at(dest) != ' ')
						return false;
				}
				// for two space move, program will check 1 space ahead first
				// 4. same column - can move 2 steps when at row 6 (rows: [0-7]) if nothing directly infront
				if (orig.col == dest.col)
				{
					if (distance < -2 || board->at(dest) != ' ' || orig.row != 6)
						return false;
				}
				// 5. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront and same team
				if( ( are_dependent(coordinate(1,1), move->get_direction()) || are_dependent(coordinate(-1,1), move->get_direction()) ) )
				{
					if(distance != 1 && targeted_piece.side() == moving_piece.side())
						return false;
				}
				// 6. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront and opposite team
				if( ( are_dependent(coordinate(1,1), move->get_direction()) || are_dependent(coordinate(-1,1), move->get_direction()) ) )
				{
					if(distance == 1 && targeted_piece.side() != moving_piece.side())
						return validMove;
				}
			}
			return validMove;
		};
};
