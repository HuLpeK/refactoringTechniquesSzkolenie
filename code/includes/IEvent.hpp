#pragma once
#include "IPlayer.hpp"

class IEvent{
public:
    virtual void processPlayer(IPlayer::ptr)=0;
};