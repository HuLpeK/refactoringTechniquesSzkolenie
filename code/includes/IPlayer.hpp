

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
    int getMoney(){
        return money;
    }

    void movePlayer(int pos){
        piece->movePiece(pos);
    }

    int getPosition(){return piece->getPosition();}
    bool operator==(const IPlayer& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const IPlayer& player);
private:
    std::shared_ptr<IPiece> piece;
    int money {100};
    const std::string name {};

    int ID;
};