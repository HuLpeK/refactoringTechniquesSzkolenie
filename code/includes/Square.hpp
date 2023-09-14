#pragma once
#include "IAction.hpp"
#include <memory>
#include <list>
class Square {
public:
    Square()=default;

    Square(std::initializer_list<std::shared_ptr<IActionOnStep>> il);

    void addActionOnStep(std::shared_ptr<IActionOnStep> newEvent);
    void addActionOnPassby(std::shared_ptr<IActionOnPassby> newEvent);
    void addActionOnBoth(std::shared_ptr<IActionOnboth> newEvent);

    void processActionsOnStep(std::shared_ptr<class Player> player);
    void processActionOnPassby(std::shared_ptr<class Player> player);
private:

    std::list<std::shared_ptr<IActionOnStep>> actionListOnStop;
    std::list<std::shared_ptr<IActionOnPassby>> actionListOnPassby;
};