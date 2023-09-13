

#pragma once

#include <string>
#include <iostream>
#include <utility>

    class IPlayer{
    public:
        IPlayer(std::string currName);
        virtual void receiveMoney(int amountOfMoney);

        friend std::ostream& operator<<(std::ostream& out, const IPlayer& player);

    private:

        int money {};
        const std::string name {};
    };