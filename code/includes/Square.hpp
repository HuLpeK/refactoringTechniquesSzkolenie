#pragma once
#include "IEvent.hpp"
#include <memory>
#include <list>
class Square {
public:
    Square()=default;
    virtual ~Square() {}
    Square(std::initializer_list<std::shared_ptr<IEvent>> il);

    void addEvent(std::shared_ptr<IEvent> newEvent);

    void processEvents(std::shared_ptr<class Player> player);
private:

    std::list<std::shared_ptr<IEvent>> eventList;
};