#pragma once

#include "IAction.hpp"
#include "Player.hpp"
namespace Actions{

    class Penelty : public IActionOnStep{
         void processPlayer(std::shared_ptr<class Player> player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IActionOnStep{
        void processPlayer(std::shared_ptr<class Player> player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IActionOnStep{
        void processPlayer(std::shared_ptr<class Player> player) override{
            player->receiveMoney(10);
        }
    };

} // namespace Actions
