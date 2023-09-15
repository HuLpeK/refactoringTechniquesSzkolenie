#include <utility>

#include "../includes/Player.hpp"
#include "Actions.hpp"
#include "../includes/Board.hpp"
#include "Piece.hpp"
#include "BoardIterator.hpp"
#include "Board.hpp"


void Player::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = amountOfMoney+money;
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Imie: " << player.name << " Pieniadze: " << player.money << " " << *player.piece;
    return out;
}

Player::Player(std::string playerName, std::shared_ptr<Board> bo) : name(std::move(playerName)), boardIterator(std::make_shared<BoardIterator>(bo)) { // TODO: dodac iterator
    piece = std::make_shared<Piece>(STARTINGPOSTION);

}

bool Player::decideToBuy(){
    return true;
}

bool Player::operator==(const Player &lhs) const {
    return playerID == lhs.playerID;
}

void Player::move(int pos) { // todo zastanowic sie czy dwa razy sie nie

    for(int i = 0; i < pos - 1; i++, moveForwardByOne())
        boardIterator->next().processActionOnPassby(shared_from_this());
    
    boardIterator->get().processActionsOnStep(shared_from_this());
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

//    handleMovingThroughStart(startingPosition)
//    board->at(getPosition()).processActionsOnStep(shared_from_this());

    if(isPlayerBankrupt())
        throw std::out_of_range("I'm Bankrupt!");
}

bool Player::isPlayerBankrupt() const {
    return money < 0;
}

void Player::handleMovingThroughStart(int startingPosition) {
    if(startingPosition <= getPosition() or getPosition() == 0)
        return;

    board->at(STARTINGPOSTION).processActionsOnStep(shared_from_this());
}

void Player::moveForwardByOne() {
    boardIterator->next();
}

