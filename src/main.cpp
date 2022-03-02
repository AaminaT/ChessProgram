#include <iostream>
#include "Model/game.hpp"
#include "Model/board.hpp"

int main(int argc, char* argv[]) {
     Board board = Board();
     board.print(std::cout);
     Board::piece_iterator it = board.begin();
     for(it; it != board.end(); it++)
         std::cout << "piece: " << (*it).piece() << " side: " << (*it).side() << std::endl;

     return 0;
}
