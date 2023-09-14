#pragma once

#include "Board.hpp"

class BoardIterator{
    public:
        BoardIterator(Board& b) : board(b){}
        Square& next();
        Square& get();
    private:
        Board& board;
        int currentIndex = 0;
};