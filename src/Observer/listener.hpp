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
            bool found = false;
            for(auto i = observers->begin(); i != observers->end(); i++)
                if(*i == obs) {
                    observers->erase(i);
                    found = true;
                    break;
                {
            return found;
        }
};

#endif // __LISTENER_HPP__
