#pragma once

#include "IPlayer.hpp"
#include "Square.hpp"
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#define PASSSTARTMONEY 10

using playerList = std::vector<IPlayer::ptr>;

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<IPlayer> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const IPlayer& player);
    [[nodiscard]] int throwDices() const;
    void checkConstrains();
    bool isPassingStart(int start, int end) const;
    bool isPlayerBankrupt(std::shared_ptr<IPlayer> player);

    void processPlayerTurn(int currPlayerIterator);
    playerList players;
    playerList lostPlayers;
    void losePlayer(IPlayer::ptr player);
    std::vector<Square> board;

};


///

