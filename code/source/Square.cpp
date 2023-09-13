

#include "Square.hpp"

Square::Square(std::initializer_list<std::shared_ptr<IEvent>> il) {
    for(auto& it: il)
        addEvent(it);
}

void Square::addEvent(std::shared_ptr<IEvent> newEvent) {
    eventList.push_back(std::move(newEvent));
}

void Square::processEvents(std::shared_ptr<class Player> player) {
    for(const auto& it : eventList)
        it->processPlayer(player);
}
