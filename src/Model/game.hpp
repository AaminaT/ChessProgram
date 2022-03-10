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
		pieces.insert('p', new Pawn());
		pieces.insert('k', new King());
		pieces.insert('q', new Queen());
		pieces.insert('r', new Rook());
		pieces.insert('b', new Bishop());
		pieces.insert('n', new Knight());
        }
        
        /*~Game() {
            for(Piece* p: pieces)
                delete p;
            for(Board* b: history)
                delete b;
        }*/

        virtual void update(Message* msg, Observer* src) {
            // msg instance of (message implementation)
            // ...
            // handle message
            // ...
            // delete message
        }

        virtual void notifyObservers(Message* msg, Observer* src) {
            observers->at(turn%2)->update(msg, src);
        }
};

#endif //__GAME_HPP__
