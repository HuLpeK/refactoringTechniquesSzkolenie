#include "../includes/Player.hpp"


void Player::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = amountOfMoney+money;
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Imie: " << player.name << " Pieniadze: " << player.money << " " << *player.piece;
    return out;
}

Player::Player(std::string playerName) : name(std::move(playerName))  {
    piece = std::make_shared<Piece>(STARTINGPOSTION);

}

bool Player::operator==(const Player &lhs) const {
    return playerID == lhs.playerID;
}

void Player::movePlayer(int pos) {
        piece->movePiece(pos);
}

int Player::getMoney() const{
        return money;
}

int Player::getPosition() {
    return piece->getPosition();
}
