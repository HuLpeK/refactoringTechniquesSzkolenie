#include "dice.hpp"


int dice::throwTwoDices()  {
    return throwDice() + throwDice();
}

int dice::throwDice()  {
    return std::uniform_int_distribution<int>(1,DICESIZE)(generator);
}
