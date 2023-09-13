#pragma once

#include "Player.hpp"
#include "Events.hpp"
#include "Square.hpp"
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#define PASSSTARTMONEY 10

using playerList = std::vector<Player::ptr>;

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<Player> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const Player& player);
    [[nodiscard]] int throwDices() const;
    void checkConstrains();
    bool isPassingStart(int start, int end) const;
    bool isPlayerBankrupt(std::shared_ptr<Player> player);

    void processPlayerTurn(int currPlayerIterator);
    playerList players;
    playerList lostPlayers;
    void losePlayer(Player::ptr player);
    std::vector<Square> board;

};


///

