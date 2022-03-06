#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include "message.hpp"
#include "../Model/coordinate.hpp"

class Move: public Message {
    private:
        coordinate* origin;
        coordinate* destination;
        int side;

    public:
        Move(coordinate* o, coordinate* d): Message(), origin{o}, destination{d} {}
        
        ~Move() {
            delete origin;
            delete destination;
        }

        void set_origin(coordinate* c) {
            delete origin;
            origin = c;
        }

        void set_destination(coordinate* c) {
            delete destination;
            destination = c;
        }

        coordinate get_direction() {
            coordinate dir = *destination - *origin;
            
	    int abs_row = dir.row * (dir.row < 0? -1: 1);
            int abs_col = dir.col * (dir.col < 0? -1: 1); 
            
            if(0 < abs_row && abs_row <= abs_col) {
                dir.row /= abs_row;
                dir.col /= abs_row;
            }
            else if(0 < abs_col) {
                dir.row /= abs_col;
                dir.col /= abs_col;
            }

            return dir;
        }

        coordinate* get_origin() {
            return origin;
        }

        coordinate* get_destination() {
            return destination;
        }

        virtual std::string info() {
            std::stringstream ss;
            ss << "Move from (" << origin->row << ", " << origin->col
               << ") to (" << destination->row << ", " << destination->col << ")." << std::endl;
            return ss.str();
        }
};

#endif
