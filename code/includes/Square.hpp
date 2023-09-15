#pragma once
#include "IAction.hpp"
#include <memory>
#include <list>

class BlackHole{
public:
    BlackHole()=default;
    bool isActive(){
        numOfTurnes++;
        return numOfTurnes%2;
    }

private:
    int numOfTurnes {};

};
class Square {
public:
    Square()=default;

    Square(std::initializer_list<std::shared_ptr<IActionOnStep>> il);

    void addActionOnStep(std::shared_ptr<IActionOnStep> newEvent);
    void addActionOnPassby(std::shared_ptr<IActionOnPassby> newEvent);
    void addActionOnBoth(std::shared_ptr<IActionOnboth> newEvent);
    void addBlackHole();


    void processActionsOnStep(std::shared_ptr<class IPlayer> player);
    void processActionOnPassby(std::shared_ptr<class IPlayer> player);
private:

    bool isBlackHoleActive();

    void returnToStateOfBh(bool isBhActive);
    std::list<std::shared_ptr<IActionOnStep>> actionListOnStop;
    std::list<std::shared_ptr<IActionOnPassby>> actionListOnPassby;

    std::unique_ptr<BlackHole> bh;
};