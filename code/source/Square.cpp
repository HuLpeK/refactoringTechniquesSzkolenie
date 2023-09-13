

#include "Square.hpp"

Square::Square(std::initializer_list<std::shared_ptr<IEvent>> il) {
    for(auto& it: il)
        addEvent(it);
}

void Square::addEvent(const std::shared_ptr<IEvent>& newEvent) {
    eventList.push_back(newEvent);
}

void Square::processEvents(IPlayer::ptr player) {
    for(const auto& it : eventList)
        it->processPlayer(player);
}
