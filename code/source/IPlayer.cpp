#include <utility>

#include "../includes/IPlayer.hpp"
#include "Actions.hpp"
#include "../includes/Board.hpp"
#include "Piece.hpp"
#include "BoardIterator.hpp"
#include "Board.hpp"


void IPlayer::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money += amountOfMoney;
}

std::ostream &operator<<(std::ostream &out, const IPlayer &player) {
    out << "Imie: " << player.name << " Pieniadze: " << player.money << " " << *player.piece;
    return out;
}

IPlayer::IPlayer(std::string playerName, std::shared_ptr<Board> bo) : name(std::move(playerName)), boardIterator(std::make_shared<BoardIterator>(bo)) { // TODO: dodac iterator
    piece = std::make_shared<Piece>(STARTINGPOSITION);

}

bool IPlayer::operator==(const IPlayer &lhs) const {
    return playerID == lhs.playerID;
}

void IPlayer::move(int pos) { // todo zastanowic sie czy dwa razy sie nie

    for(int i = 0; i < pos - 1; i++, moveForwardByOne())
        boardIterator->next().processActionOnPassby(shared_from_this());
    
    boardIterator->get().processActionsOnStep(shared_from_this());
}

int IPlayer::getMoney() const{
        return money;
}

int IPlayer::getPosition() {
    return piece->getPosition();
}

void IPlayer::performMove(int diceRolled) {
    const int startingPosition = getPosition();
    move(diceRolled);

    if(isPlayerBankrupt())
        throw std::out_of_range("I'm Bankrupt!");
}

bool IPlayer::isPlayerBankrupt() const {
    return money < 0;
}

void IPlayer::moveForwardByOne() {
    boardIterator->next();
}

