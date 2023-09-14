#pragma once

#include <utility>

#include "Board.hpp"

class BoardIterator{
    public:
        BoardIterator(std::shared_ptr<Board> b) : board(std::move(b)){}
        Square& next();
        Square& get();
    private:
        std::shared_ptr<Board> board;
        int currentIndex = 0;
};