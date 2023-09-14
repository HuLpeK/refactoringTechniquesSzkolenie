#pragma once


#include <memory>

class IAction{
public:
    virtual void processPlayer(std::shared_ptr<class Player>)=0;
};