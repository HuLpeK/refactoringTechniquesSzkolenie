#pragma once
#include "IAction.hpp"
#include <memory>
#include <list>
class Square {
public:
    Square()=default;

    Square(std::initializer_list<std::shared_ptr<IAction>> il);

    void addEvent(std::shared_ptr<IAction> newEvent);

    void processEvents(std::shared_ptr<class Player> player);
private:

    std::list<std::shared_ptr<IAction>> eventList;
};