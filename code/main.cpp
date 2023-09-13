#include<iostream>

#include "includes/Player.hpp"
#include "includes/Piece.hpp"
#include "MonopolyGame.hpp"

int main() {
    Player x("12");
//    std::cout << Hubert << '\n';
//
//    Piece piece(10);
//    std::cout << piece << "\n";

    MonopolyGame game{x, {"13"}};

    game.startGame();
}