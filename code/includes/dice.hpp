#pragma once
#include <random>

class dice {
public:
    int throwTwoDices();

private:
   int throwDice();

   const int DICESIZE = 6;

   std::random_device rd;
};


