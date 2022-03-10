#ifndef __BOARD_UI_HPP__
#define __BOARD_UI_HPP__

#include "../Observer/listener.hpp"
#include "../Messages/update.hpp"
#include "../Model/board.hpp"

class BoardUI: public Observer, public Listener {
    private:
        void inputHandler(coordinate& orig, coordinate& dest) {
            
        }

    public:
        BoardUI() {}

        virtual void update(Message* msg, Observer* src) {
            switch(msg->m_type()) {
                case 'i':
                    std::cout << "The entered move is invalid!" << std::endl;
                case 'b':
                    UpdateBoard* b = dynamic_cast<UpdateBoard*>(msg);
                    // print updated board
                    std::cout << "Enter a move: " << std::endl;
                    // request/verify input
                    
                    inputHandler
                    notifyObservers(new Move(), this);
                    break;
                case 'e':
                    std::cout << "The entered move is invalid!" << std::endl;
                    break;
                default:
                    break;
            }

            delete msg;
        }


};

#endif