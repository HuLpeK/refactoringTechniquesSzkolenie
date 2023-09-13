#include "../includes/IPlayer.hpp"


void IPlayer::receiveMoney(int amountOfMoney) { //TODO zastanowic sie co jesli money < 0
    money = std::max(0,amountOfMoney+money);
}

std::ostream &operator<<(std::ostream &out, const IPlayer &player) { //TODO dorobic wypisywanie pozycji
    out << "Imie: " << player.name << " Money: " << player.money;
    return out;
}

IPlayer::IPlayer(std::string playerName) : name(playerName)  {

}
