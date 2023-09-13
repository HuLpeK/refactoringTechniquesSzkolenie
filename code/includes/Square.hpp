#pragma once
#include "IEvent.hpp"
#include <memory>
#include <list>
class Square {
public:
    Square(std::initializer_list<std::shared_ptr<IEvent>> il);

    void addEvent(const std::shared_ptr<IEvent>& newEvent);

    void processEvents(IPlayer::ptr player);
private:

    std::list<std::shared_ptr<IEvent>> eventList;
};


