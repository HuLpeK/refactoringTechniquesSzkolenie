#pragma once

#include "IAction.hpp"

namespace Actions{

    class Penelty : public IAction{
         void processPlayer(Player::ptr player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IAction{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IAction{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(10);
        }
    };

} // namespace Actions
