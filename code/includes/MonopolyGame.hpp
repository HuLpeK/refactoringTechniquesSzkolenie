#pragma once

#include "Player.hpp"
#include "Events.hpp"
#include "Square.hpp"
#include "dice.hpp"
#include <algorithm>
#include <vector>

#define PASSSTARTMONEY 10

using playerList = std::vector<Player::ptr>;

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<Player> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const Player& player);
    void checkConstrains();
    bool isPassingStart(int start, int end) const;
    bool isPlayerBankrupt(std::shared_ptr<Player> player);
    void processPlayerTurn(int currPlayerIterator);
    void losePlayer(Player::ptr player);

    dice rollingDice;
    playerList players;
    playerList lostPlayers;
    std::vector<Square> board;

};


///

