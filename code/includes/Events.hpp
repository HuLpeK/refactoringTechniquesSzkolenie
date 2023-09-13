#pragma once

#include "IEvent.hpp"
namespace Events{

    class Penelty : public IEvent{
         void processPlayer(Player::ptr player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IEvent{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IEvent{
        void processPlayer(Player::ptr player) override{
            player->receiveMoney(100);
        }
    };

} // namespace Events
