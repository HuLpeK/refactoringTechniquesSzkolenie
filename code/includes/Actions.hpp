#pragma once

#include "IAction.hpp"
#include "IPlayer.hpp"

namespace Actions{

    class Penelty : public IActionOnStep{
         void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
             player->receiveMoney(-10);
         }
    };

    class Reward : public IActionOnStep{
        void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
            player->receiveMoney(10);
        }
    };

    class Start : public IActionOnPassby{
        void processPlayerOnPassby(std::shared_ptr<class IPlayer> player) override{
            player->receiveMoney(10);
        }
    };

    class Deposit : public IActionOnboth{
    public:
        void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override {
            player->receiveMoney(depositAmount);
            depositAmount = 0;
        }

        void processPlayerOnPassby(std::shared_ptr<class IPlayer> player) override{
            const int wantedMoneyToTake {5};
            const int takenMoney = std::min(player->getMoney(), std::abs(wantedMoneyToTake));

            player->receiveMoney(wantedMoneyToTake);
            depositAmount += takenMoney;
        }
    private:
        int depositAmount = 0;
    };

    class Property : public IActionOnStep{
        public:
            void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
                if(isOwner(player))
                    return;

                if(isOccupied()){

                    int moneyToReceive = std::min(player->getMoney(), rentPrice);
                    
                    player->receiveMoney(-1 * rentPrice);
                    
                    ownerPlayer->receiveMoney(moneyToReceive);

                    return;
                }

               processOfBuyingProperty(player);
            }


        private:
            bool isOccupied(){return ownerPlayer != nullptr;}
            bool isOwner(std::shared_ptr<class IPlayer> player){return ownerPlayer == player;}
            void processOfBuyingProperty(std::shared_ptr<class IPlayer> player){
                bool isGoingToBuy = player->decideToBuy();
                if(isGoingToBuy){
                    if(player->getMoney() < buyPrice) 
                        throw std::out_of_range("You don't have enough money");
                    
                    ownerPlayer = player;
                    player->receiveMoney(-buyPrice);
                }
            }
            const int buyPrice = 10;
            const int rentPrice = 5;
            std::shared_ptr<class IPlayer> ownerPlayer{nullptr};
    };
    

} // namespace Actions
