#pragma once
#include "Player.hpp"

class IEvent{
public:
    virtual void processPlayer(Player::ptr)=0;
};