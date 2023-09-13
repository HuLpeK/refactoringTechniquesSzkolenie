

#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <memory>
#include "Piece.hpp"
#include "ID.hpp"

#define STARTINGPOSTION 0

class Player{
public:
    Player(std::string currName);
    virtual void receiveMoney(int amountOfMoney);
    [[nodiscard]] int getMoney() const;

    void movePlayer(int pos);

    int getPosition();

    bool operator==(const Player& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& player);

    using ptr = std::shared_ptr<Player>;

private:
    std::shared_ptr<Piece> piece;
    int money {100};
    const std::string name {};

    ID playerID; //todo: powtorzenieTypu
};