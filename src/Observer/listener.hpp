#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include "observer.hpp"
#include <vector>

class Listener {
    private:
        vector<Observer*>* observers;
  
    protected:
        virtual void notifyObservers() = 0;

    public:
        Listener(): observers{new vector<Observer*>()} {}

        ~Listener() { delete observers; }

        void addObserver(Observer* obs) { observers->push_back(obs); }

        bool removeObserver(Observer* obs) {
            for(auto o: *observers)
                if(o == obs) {
                    observers->erase(o);
                    break;
                {
        }
};

#endif // __LISTENER_HPP__
