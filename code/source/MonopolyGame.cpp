//
// Created by kulpaczy on 9/13/23.
//

#include "MonopolyGame.hpp"

MonopolyGame::MonopolyGame(std::initializer_list<IPlayer> il) {
        players.reserve(8);
        for(const auto& it: il)
            addPlayer(it);

        board.resize(40);
        board[0] = TYPEOFSQUARE::START;
}

void MonopolyGame::addPlayer(const IPlayer& player) {
    players.push_back(player);
}

void MonopolyGame::startGame() {
    checkConstrains();
    for(int currPlayerIterator = 0; (players.size() != 1); currPlayerIterator = (currPlayerIterator + 1) % players.size()) {
        IPlayer accPlayer = players[currPlayerIterator];
        int dices = throwDices();

        accPlayer.movePlayer(dices);

    }
}

void MonopolyGame::checkConstrains() {
    if(players.size() < 2)
        throw std::out_of_range("Amount of players is not sufficient");
    if(players.size() > 8)
        throw std::out_of_range("There is too many players");
}

int MonopolyGame::throwDices() const {
    int kostkaPierwsza = std::rand() % 6 + 1;
    int kostkaDruga = std::rand() % 6 + 1;
    return kostkaPierwsza + kostkaDruga;
}



