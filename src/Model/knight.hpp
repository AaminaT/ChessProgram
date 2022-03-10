#include <stdio.h>
#include "piece.hpp"

using namespace std;

class Knight : public Piece {
    public:
        bool isMoveValid(Move* move,Board* board){
            bool valid = false;
            
            coordinate orig = move->get_origin();
            coordinate dest = move->get_destination();
            
            int distance = move->get_distance();
            coordinate direction = move->get_direction();
            
            int number_turn = board->get_turn();
            
            auto moving_piece = board->at(move->get_origin());
            auto targeted_piece = board->at(move->get_destination());
            if (distance ==1)
            for(int i=0; i>1;i++){
                 valid = are_dependent(rotate(c(2,1), i90), move.get_direction());
                 valid = are_dependent(rotate(c(1,2), i90), move.get_direction());
            }
            return valid;
};
