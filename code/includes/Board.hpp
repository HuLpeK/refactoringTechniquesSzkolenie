#pragma once

#include "Square.hpp"
#include "Actions.hpp"
#include <vector>


class Board{
    public:
        Board(const int size) : number_of_squares(size), start_square(0){ 
            squares.resize(number_of_squares);
            squares[start_square].addEvent(std::make_shared<Actions::Start>());
        }

        Square& at(int position);

    private:
        const int number_of_squares;
        const int start_square;
        std::vector<Square> squares;
};