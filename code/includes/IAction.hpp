#pragma once


#include <memory>

class IActionOnStep{
public:
    virtual void processPlayerOnStep(std::shared_ptr<class Player>)=0;
};

class IActionOnPassby{
public:
    virtual void processPlayerOnPassby(std::shared_ptr<class Player>)=0;
};

class IActionOnboth : public IActionOnStep, public IActionOnPassby{

};
