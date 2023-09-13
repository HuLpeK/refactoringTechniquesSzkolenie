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
    PENELTY
};

class MonopolyGame {
public:
    MonopolyGame(std::initializer_list<IPlayer> il);

    void addPlayer(const IPlayer& player);

    void startGame();

private:
    int throwDices() const;
    void checkConstrains();
    std::vector<IPlayer> players;
    std::vector<IPlayer> lostPlayers;

    std::vector<TYPEOFSQUARE> board;

};



