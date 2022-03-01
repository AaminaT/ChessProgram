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
        Move(): Message() {}
        
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
            
        }

        coordinate get_origin() {
            
        }

        coordinate get_destination() {
        
        }
};

#endif
