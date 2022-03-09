#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include "../Observer/msghandler.hpp"
#include<string>
#include<sstream>

class Message {
    public:
        virtual ~Message() {}
        virtual std::string info() = 0;
        virtual void accept(MsgHandler*, Observer*) = 0;
};

#endif //__MESSAGE_HPP__
