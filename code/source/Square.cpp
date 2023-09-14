

#include "Square.hpp"

Square::Square(std::initializer_list<std::shared_ptr<IActionOnStep>> il) {
    for(auto& it: il)
        addActionOnStep(it);
}

void Square::addActionOnStep(std::shared_ptr<IActionOnStep> newEvent) {
    actionListOnStop.push_back(std::move(newEvent));
}

void Square::addActionOnPassby(std::shared_ptr<IActionOnPassby> newEvent) {
    actionListOnPassby.push_back(std::move(newEvent));
}

void Square::addActionOnBoth(std::shared_ptr<IActionOnboth> newEvent) {
    addActionOnPassby(newEvent);
    addActionOnStep(newEvent);
}


void Square::processActionsOnStep(std::shared_ptr<class Player> player) {
    for(const auto& it : actionListOnStop)
        it->processPlayerOnStep(player);

}

void Square::processActionOnPassby(std::shared_ptr<struct Player> player) {
    for(const auto& it : actionListOnPassby)
        it->processPlayerOnPassby(player);

}
