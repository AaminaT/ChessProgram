#include <iostream>
#include "Model/game.hpp"
#include "Model/board.hpp"

int main(int argc, char* argv[]) {
     Board board = Board();
     board.print(std::cout);
     Board::board_iterator it = board.begin();
     for(it; it != board.end(); it++)
         std::cout << (*it).piece();
     std::cout << std::endl;

     return 0;
}
