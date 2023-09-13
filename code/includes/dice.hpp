#pragma once
#include <random>

class dice {
public:
    int throwTwoDices();
    dice()=default;

private:
   int throwDice();

   const int DICESIZE = 6;

    std::default_random_engine generator;
};


