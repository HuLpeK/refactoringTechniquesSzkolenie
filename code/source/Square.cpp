

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

    bool isBhActive = isBlackHoleActive(); // 1 nie wykonalo
    addActionOnPassby(newEvent);  // 0 NIe Wykonalo sie

    returnToStateOfBh(isBhActive);

    addActionOnStep(newEvent); // nie Wykona
}


void Square::processActionsOnStep(std::shared_ptr<class IPlayer> player) {
    if(!isBlackHoleActive())
        return;
    for(const auto& it : actionListOnStop)
        it->processPlayerOnStep(player);

}

void Square::processActionOnPassby(std::shared_ptr<class IPlayer> player) {
    if(!isBlackHoleActive())
        return;
    for(const auto& it : actionListOnPassby)
        it->processPlayerOnPassby(player);

}

bool Square::isBlackHoleActive() {
    if(bh != nullptr)
        return bh->isActive();
    return false;
}

void Square::returnToStateOfBh(bool isBhActive) {
    bh = std::make_unique<BlackHole>(); // 0
    if(isBhActive)
        bh->isActive(); // 1
}

void Square::addBlackHole() {
    bh = std::make_unique<BlackHole>();
}
