#ifndef __BOARD_UI_HPP__
#define __BOARD_UI_HPP__

#include "../Observer/listener.hpp"
#include "../Messages/update.hpp"
#include "../Model/board.hpp"
#include <iostream>

class BoardUI: public Observer, public Listener {
    private:
        void inputHandler(coordinate& orig, coordinate& dest) {
		std::cout << "Enter your piece's row: ";
	    	std::cin  >> orig.row;
		std::cout << std::endl;
		while(orig.row < 0 || orig.row > 7)
		{
			std::cout << "Invalid row, please try again: ";
			std::cin >> orig.row;
			std::cout << std::endl;
		}

		std::cout << "Enter your piece's col: ";
		while(orig.col < 0 || orig.col > 7)
		{
			std::cout << "Invalid col, please try again: ";
			std::cin >> orig.col;
			std::cout << std::endl;
		}

		std::cout << "Enter your destination row: ";
		std::cin >> dest.row;
		std::cout << std::endl;
		while(dest.row < 0 || dest.row > 7)
		{
			std::cout << "Invalid row, please try again: ";
			std::cin >> dest.row;
			std::cout << std::endl;
		}

		std::cout << "Enter your destination col: ";
		std::cin >> dest.col;
		std::cout << std::endl;
		while(dest.col < 0 || dest.col > 7)
		{
			std::cout << "Invalid col, please try again: ";
			std::cin >> dest.col;
			std::cout << std::endl;
		}
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
