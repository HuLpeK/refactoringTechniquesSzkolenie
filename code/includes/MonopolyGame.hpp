#pragma once

#include "IPlayer.hpp"
#include "algorithm"
#include <vector>
#include <cstdlib>
#include <ctime>

using playerT = std::shared_ptr<IPlayer>;
using playerList = std::vector<playerT>;

enum class TYPEOFSQUARE{
    DEFAULT,
    START,
    REWARD,
    PENALTY
};

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<IPlayer> il);

    void startGame();

private:
    void printGame();
    void addPlayer(const IPlayer& player);
    [[nodiscard]] int throwDices() const;
    void checkConstrains();
    playerList players;
    playerList lostPlayers;
    void losePlayer(playerT player);
    std::vector<TYPEOFSQUARE> board;

};


///

