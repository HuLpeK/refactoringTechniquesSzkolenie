#pragma once

#include "IAction.hpp"
#include "Player.hpp"
namespace Actions{

    class Penelty : public IActionOnStep{
         void processPlayerOnStep(std::shared_ptr<class Player> player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IActionOnStep{
        void processPlayerOnStep(std::shared_ptr<class Player> player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IActionOnPassby{
        void processPlayerOnPassby(std::shared_ptr<class Player> player) override{
            player->receiveMoney(10);
        }
    };

    class Deposit : public IActionOnboth{
    public:
        void processPlayerOnStep(std::shared_ptr<class Player> player) override {
            player->receiveMoney(depositAmount);
            depositAmount = 0;
        }

        void processPlayerOnPassby(std::shared_ptr<class Player> player) override{
            const int wantedMoneyToTake {5};
            const int takenMoney = std::min(player->getMoney(), std::abs(wantedMoneyToTake));

            player->receiveMoney(wantedMoneyToTake);
            depositAmount += takenMoney;
        }
    private:
        int depositAmount = 0;
    };

} // namespace Actions
