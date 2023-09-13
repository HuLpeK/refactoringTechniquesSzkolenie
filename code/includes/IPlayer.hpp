

#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <memory>
#include "IPiece.hpp"

#define STARTINGPOSTION 0

class IPlayer{
public:
    IPlayer(std::string currName);
    virtual void receiveMoney(int amountOfMoney);
    [[nodiscard]] int getMoney() const;

    void movePlayer(int pos);

    int getPosition();

    bool operator==(const IPlayer& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const IPlayer& player);

    using ptr = std::shared_ptr<IPlayer>;

private:
    std::shared_ptr<IPiece> piece;
    int money {100};
    const std::string name {};

    int ID; //todo: dopisac klase ID
};