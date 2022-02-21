#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include "observer.hpp"

class Listener {
    public:
        virtual ~Listener() {}
        virtual void addObserver(Observer* obs) = 0;
        virtual bool removeObserver(Observer* obs) = 0;
        virtual void notifyObservers(Message* message, Observer* src) = 0;
};

#endif // __LISTENER_HPP__
