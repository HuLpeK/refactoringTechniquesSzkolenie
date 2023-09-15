#include "Dice.hpp"


int Dice::throwTwoDices()  {
    return throwDice() + throwDice();
}

int Dice::throwDice()  {
    return std::uniform_int_distribution<int>(1,DICESIZE)(generator);
}
