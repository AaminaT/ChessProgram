#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "../Observer/listener.hpp"
#include "../Observer/msghandler.hpp"
#include "board.hpp"
#include "piece.hpp"
#include <stack>
#include <unordered_map>

class Game: public Observer, public Listener, public MsgHandler {
    private:
	    int id;
        Board* current;
        std::stack<Board*> history;
        std::unordered_map<char, Piece*> pieces;

    public:
	Game(Observer* player1, Observer* player2): Observer(), Listener(), MsgHandler() {
            this->addObserver(player1);
            this->addObserver(player2);
        }
        
        ~Game() {
            for(auto p: pieces)
                delete p.second;
            for(Board* b: history._Get_container())
                delete b;
        }

        virtual void update(Message* msg, Observer* src) {
            msg->accept(this, src);
        }

        virtual void notifyObservers(Message* msg, Observer* src) {
            observers->at(current->get_turn()%2)->update(msg, src);
        }

        virtual void handle(Move* mov, Observer* src) {
            auto ptm = current->at(mov->get_origin());
            Piece* ruleset = nullptr;

            if(ptm.hasPiece()) 
                ruleset = pieces.at(ptm.piece());

            if(ruleset != nullptr && (current->get_turn()%2 == 0) == ptm.isWhite() && ruleset->isMoveValid(mov, current)) {
                // apply move
                history.push(current);
                current = current->move(mov->get_origin(), mov->get_destination(), 200);
                // Message* upd = new UpdateBoard(current);
                // notifyObservers(upd, nullptr);
            }
            else {
                // notify user of invalid move
                // Message* inv = new InvalidMove(*mov);
                // src->update(inv, nullptr);
            }
        }

        /*virtual void handle(UndoMove* und, Observer* src) = 0;
        virtual void handle(UpdateBoard* upd, Observer* src) = 0;
        virtual void handle(Promotion* pro, Observer* src) = 0;
        virtual void handle(InvalidMove* inv, Observer* src) = 0;
        virtual void handle(EndGame* end, Observer* src)*/
};

#endif //__GAME_HPP__
