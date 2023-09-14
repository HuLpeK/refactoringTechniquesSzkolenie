#pragma once

#include "Square.hpp"
#include "Actions.hpp"
#include <vector>


class Board{
    public:
        Board(const int size);

        Square& at(int position);

    private:
        const int number_of_squares;
        const int start_square;
        std::vector<Square> squares;
};

