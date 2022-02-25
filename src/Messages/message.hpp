#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include<string>

class Message {
    public:
        virtual ~Message() {}
        virtual std::string info() = 0;
};

#endif //__MESSAGE_HPP__
