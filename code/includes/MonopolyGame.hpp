#pragma once

#include "IPlayer.hpp"
#include "algorithm"
#include <vector>
#include <cstdlib>
#include <ctime>

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
    std::vector<std::shared_ptr<IPlayer>> players;
    std::vector<std::shared_ptr<IPlayer>> lostPlayers;
    void losePlayer(std::shared_ptr<IPlayer> player);
    std::vector<TYPEOFSQUARE> board;

};



