#pragma once

#include <utility>

#include "Board.hpp"
#include "Piece.hpp"
class BoardIterator{
    public:
        BoardIterator(std::shared_ptr<Board> b, std::shared_ptr<Piece> p) : board(std::move(b)), piece(std::move(p)) {}
        Square& next();
        Square& get();
    private:
        std::shared_ptr<Board> board;
        int currentIndex = 0;

        std::shared_ptr<Piece> piece;
};