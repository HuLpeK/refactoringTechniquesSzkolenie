#include "Player.hpp"
#include "MonopolyGame.hpp"

int main() {
    Player x("12");

    MonopolyGame game{x, {"13"}};

    game.startGame();
}