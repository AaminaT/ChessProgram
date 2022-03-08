#include "pawn.hpp"

using namespace std;

bool Pawn::IsMoveValid(Move move,Board* board)
{
	bool validMove = true;
	coordinate orig = move->get_origin();
	coordinate dest = move->get_destination();
	int distance = move->get_distance();
	int number_turn = board->get_turn()
		
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
			if (distance < 1  || piece_info->at(dest) != ' ')
				return false;
		}
		// for two space move, program will check 1 space ahead first
		// 4. same column - can move 2 steps when at row 1 (rows: [0-7]) if nothing directly infront
		if (orig.col == dest.col)
		{
			if (distance > 2 || piece_info->at(dest) != ' ' || orig.row != 1)
				return false;
		}
		// 5. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront of the
		if (orig.row != dest.row && orig.col != dest.col)
		{
			int distanceRow = dest.row - orig.row -1;
			//a pawn piece can move to either column
			int distanceCol = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
			if ((distanceRow != 0 && distanceCol != 0) || piece_info->at(dest) == ' ')
				return false;
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
			if (distance > -1 || piece_info->at(dest) != ' ')
				return false;
		}
		// for two space move, program will check 1 space ahead first
		// 4. same column - can move 2 steps when at row 6 (rows: [0-7]) if nothing directly infront
		if (orig.col == dest.col)
		{
			if (distance < -2 || piece_info->at(dest) != ' ' || orig.row != 6)
				return false;
		}
		// 5. diagonals - when pawn has another piece in that adajacent diagonal destination is 1 space infront of the
		if (orig.row != dest.row && orig.col != dest.col)
		{
			int distanceRow = orig.col - dest.col - 1;
			//a pawn piece can move to either column
			int distanceCol = (orig.col < dest.col ? (dest.col - orig.col) - 1 : (orig.col - dest.col) - 1);
			if ((distanceRow != 0 && distanceCol != 0) || piece_info->at(dest) == ' ')
				return false;
		}
	}
	return validMove;
}
