#ifndef __KING_HPP__
#define __KING_HPP__

#include <list>

#include "piece.hpp"

class King
{
public:
	bool isMoveValid(Move*, const Board*);
	int getValue() const;
	std::list<coordinate>* getDirections(Board*);
};

#endif
