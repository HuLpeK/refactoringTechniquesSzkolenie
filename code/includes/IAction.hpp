#pragma once


#include <memory>

class IActionOnStep{
public:
    virtual void processPlayer(std::shared_ptr<class Player>)=0;
};

