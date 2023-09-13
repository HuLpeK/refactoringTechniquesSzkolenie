
#include <utility>

#include "../includes/Player.hpp"

Player::Player(std::string nameOfPlayer) : IPlayer(std::move(nameOfPlayer)) {

}
