

#include "Square.hpp"

Square::Square(std::initializer_list<std::shared_ptr<IActionOnStep>> il) {
    for(auto& it: il)
        addActionOnStep(it);
}

void Square::addActionOnStep(std::shared_ptr<IActionOnStep> newEvent) {
    actionListOnStop.push_back(std::move(newEvent));
}

void Square::processActionsOnStep(std::shared_ptr<class Player> player) {
    for(const auto& it : actionListOnStop)
        it->processPlayer(player);
}
