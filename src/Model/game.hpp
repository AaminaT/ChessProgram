#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "../Observer/listener.hpp"
#include "board.hpp"
#include "piece.hpp"
#include <stack>
#include <unordered_map>

class Game: public Observer, public Listener {
	private:
	int id;
        int turn;
        std::stack<Board*> history;
        std::unordered_map<char, Piece*> pieces;

	public:
	Game(Observer* player1, Observer* player2): Observer(), Listener() {
            this->addObserver(player1);
            this->addObserver(player2);
        }
        
        ~Game() {}

        virtual void update(Message* msg, Observer* src) {
            // msg instance of StartGame
            // ...
        }

        virtual void notifyObservers(Message* msg, Observer* src = nullptr) {
            observers->at(turn%2)->update(msg, this);
        }
};

#endif //__GAME_HPP__
