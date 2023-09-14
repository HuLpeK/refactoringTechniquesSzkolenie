#include <utility>

#include "../includes/Player.hpp"
#include "Actions.hpp"


void Player::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = amountOfMoney+money;
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Imie: " << player.name << " Pieniadze: " << player.money << " " << *player.piece;
    return out;
}

Player::Player(std::string playerName, std::vector<Square>& bo) : name(std::move(playerName)), board(bo)  {
    piece = std::make_shared<Piece>(STARTINGPOSTION);
}

bool Player::operator==(const Player &lhs) const {
    return playerID == lhs.playerID;
}

void Player::move(int pos) {
        piece->movePiece(pos);
}

int Player::getMoney() const{
        return money;
}

int Player::getPosition() {
    return piece->getPosition();
}

void Player::performMove(int diceRolled) {
    const int startingPosition = getPosition();
    move(diceRolled);

    handleMovingThroughStart(startingPosition);
    board[getPosition()].processEvents(shared_from_this());

    if(isPlayerBankrupt())
        throw std::out_of_range("I'm Bankrupt!");
}

bool Player::isPlayerBankrupt() const {
    return money < 0;
}

void Player::handleMovingThroughStart(int startingPosition) {
    if(startingPosition <= getPosition() or getPosition() == 0)
        return;

    board[STARTINGPOSTION].processEvents(shared_from_this());
}
