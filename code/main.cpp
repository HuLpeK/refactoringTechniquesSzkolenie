#include<iostream>

#include "includes/Player.hpp"
#include "includes/Piece.hpp"
#include "MonopolyGame.hpp"

int main() {
    Player Hubert("12");
    std::cout << Hubert << '\n';

    Piece piece(10);
    std::cout << piece << "\n";

    MonopolyGame game{Hubert};
}