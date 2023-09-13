#pragma once

#include "Player.hpp"
#include "Events.hpp"
#include "Square.hpp"
#include "dice.hpp"
#include <algorithm>
#include <vector>

using playerList = std::vector<Player::ptr>;

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<std::string> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const std::string &playerName);
    void checkConstrains();
    void processPlayerTurn(int currPlayerIterator);
    void losePlayer(Player::ptr player);

    dice rollingDice {};
    playerList players {};
    playerList lostPlayers {};
    std::vector<Square> board {};

};


///

