#pragma once
#include <random>

class Dice {
public:
    int throwTwoDices();
    Dice()=default;

private:
   int throwDice();

   const int DICESIZE = 6;

    std::default_random_engine generator;
};


