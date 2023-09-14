#pragma once

#include "IAction.hpp"

namespace Actions{

    class Penelty : public IActionOnStep{
         void processPlayer(Player::ptr player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IActionOnStep{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IActionOnStep{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(10);
        }
    };

} // namespace Actions
