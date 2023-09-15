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
                    payRentToOwner(player);
                    return;
                }

               processOfBuyingProperty(player);
            }


        private:
            bool isOccupied(){
                return ownerPlayer != nullptr;
            }
            bool isOwner(std::shared_ptr<class IPlayer> player){
                return ownerPlayer == player;
            }
            void processOfBuyingProperty(std::shared_ptr<class IPlayer> player){
                bool isGoingToBuy = player->decideToBuy();
                if(isGoingToBuy){
                    if(player->getMoney() < buyPrice) 
                        throw std::out_of_range("You don't have enough money");
                    
                    ownerPlayer = player;
                    player->receiveMoney(-buyPrice);
                }
            }
            void payRentToOwner(std::shared_ptr<class IPlayer> player){
                int moneyToReceive = std::min(player->getMoney(), rentPrice);
                    
                player->receiveMoney(-1 * rentPrice);
                
                ownerPlayer->receiveMoney(moneyToReceive);
            }

            const int buyPrice = 10;
            const int rentPrice = 5;
            std::shared_ptr<class IPlayer> ownerPlayer{nullptr};
    };

    class Prison : public IActionOnStep{
    public:
        void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
            player->addWaitTime(3);
        }
    };


    class RandomStepper : public IActionOnStep
    {
    public:
//        RandomStepper()=default;
        RandomStepper(std::shared_ptr<IActionOnStep> stAction, std::shared_ptr<IActionOnStep> ndAction, std::shared_ptr<IActionOnStep> rdAction){
            actions.reserve(3);
            actions.push_back(std::move(stAction));
            actions.push_back(std::move(ndAction));
            actions.push_back(std::move(rdAction));
        }
        void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
            int randomNumber = rollingDice.throwTwoDices() % actions.size();
            actions.at(randomNumber)->processPlayerOnStep(player);
        }

        private:
        std::vector<std::shared_ptr<IActionOnStep>> actions {};
        Dice rollingDice;
    };

//    class BlackHole : public IActionOnboth{
//        void processPlayerOnStep(std::shared_ptr<class IPlayer> player) override{
//            processPlayerOnPassby(player);
//        }
//        void processPlayerOnPassby(std::shared_ptr<class IPlayer> player) override{
//            numOfTurnes++;
//            if(numOfTurnes%2){
//
//            }
//        }
//
//    private:
//        std::unique_ptr<IActionOnStep> actionOnStep;
//        std::unique_ptr<IActionOnPassBy> actionOnPassby;
//        std::unique_ptr<IActionOnBoth> actionOnBoth;
//        int numOfTurnes {};
//
//        };


} // namespace Actions
