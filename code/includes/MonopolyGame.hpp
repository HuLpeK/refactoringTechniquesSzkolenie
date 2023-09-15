#pragma once

#include "IPlayer.hpp"
#include "Actions.hpp"
#include "Square.hpp"
#include "dice.hpp"
#include "Board.hpp"
#include "BoardIterator.hpp"
#include <algorithm>
#include <vector>

using playerList = std::vector<IPlayer::ptr>;

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<std::string> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const std::string &playerName);
    void checkConstrains();
    void processPlayerTurn(int currPlayerIterator);
    void losePlayer(IPlayer::ptr player);

    dice rollingDice {};
    playerList players {};
    playerList lostPlayers {};
    std::shared_ptr<Board> board ;

};


///

