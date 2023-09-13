#pragma once


#include <memory>

class IEvent{
public:
    virtual void processPlayer(std::shared_ptr<class Player>)=0;
};