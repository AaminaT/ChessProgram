#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include <list>

#include "piece.hpp"

class Rook
{ 
public:
	bool isMoveValid(Move*, const Board*);
	int getValue() const;
	std::list<coordinate>* getDirections(Board*);
private:
	int value = 5;
};

#endif
