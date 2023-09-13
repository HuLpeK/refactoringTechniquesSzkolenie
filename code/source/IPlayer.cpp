#include "../includes/IPlayer.hpp"


void IPlayer::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = amountOfMoney+money;
}

std::ostream &operator<<(std::ostream &out, const IPlayer &player) {
    out << "Imie: " << player.name << " Pieniadze: " << player.money << " " << *player.piece;
    return out;
}

int getID(){
    static int currID;
    return currID++;
}

IPlayer::IPlayer(std::string playerName) : name(std::move(playerName))  {
    piece = std::make_shared<IPiece>(STARTINGPOSTION);
    ID = getID();
}

bool IPlayer::operator==(const IPlayer &lhs) const {
    return ID == lhs.ID;
}

void IPlayer::movePlayer(int pos) {
        piece->movePiece(pos);
}

int IPlayer::getMoney() const{
        return money;
}

int IPlayer::getPosition() {
    return piece->getPosition();
}
