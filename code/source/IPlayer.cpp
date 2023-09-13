#include <utility>

#include "../includes/IPlayer.hpp"


void IPlayer::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = std::max(0,amountOfMoney+money);
}

std::ostream &operator<<(std::ostream &out, const IPlayer &player) {
    out << "Imie: " << player.name << " Money: " << player.money << " " << *player.piece;
    return out;
}

IPlayer::IPlayer(std::string playerName) : name(std::move(playerName))  {
    piece = std::make_shared<IPiece>(STARTINGPOSTION);

}