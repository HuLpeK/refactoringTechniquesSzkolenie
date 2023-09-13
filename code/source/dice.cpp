//
// Created by Hubert Kulpaczyński
// For Project refactoringTechniques
//

#include "dice.hpp"


int dice::throwTwoDices()  {
    return throwDice() + throwDice();
}

int dice::throwDice()  {
    return (int)rd() % DICESIZE + 1;
}
