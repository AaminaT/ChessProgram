#include <iostream>
#include "Model/game.hpp"
#include "Model/board.hpp"

int main(int argc, char* argv[]) {
     Board board = Board();
     board.print(std::cout);
     Board::piece_iterator it = board.begin();
     /*for(it; it != board.end(); it++)
         std::cout << "piece: " << (*it).piece() << " side: " << (*it).side() << std::endl;
     */
     coordinate* start = new coordinate(0,0);
     coordinate* end = new coordinate(4,4);
     coordinate* dir = new coordinate(1,1);

     Board::path_iterator pit = board.begin(*start, *dir);
     for(pit; pit != board.end(*end, *dir); pit++)
         std::cout << "piece: " << (*pit).piece() << " side: " << (*pit).side() << std::endl;


     return 0;
}
