#include <iostream>
#include "Model/game.hpp"
#include "Model/board.hpp"

int main(int argc, char* argv[]) {
     std::cout << "board: " << std::endl;
     Board board = Board();
     board.print(std::cout);

     std::cout << "\npieces: " << std::endl;
     Board::piece_iterator it = board.piece_begin();
     for(it; it != board.piece_end(); it++)
         std::cout << "piece: " << (*it).piece() << " side: " << (*it).side() << std::endl;
     
     coordinate* start = new coordinate(0,4);
     coordinate* end = new coordinate(7,4);
     coordinate* dir = new coordinate(1,0);

     std::cout << "\npath: " << std::endl;
     Board::path_iterator pit = board.path_begin(*start, *end, *dir);
     for(pit; pit != board.path_end(); pit++)
         std::cout << "piece: " << (*pit).piece() << " side: " << (*pit).side() << std::endl;


     return 0;
}
