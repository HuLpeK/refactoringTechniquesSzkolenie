#pragma once

#include <ostream>

class Piece{
    public:
        Piece(int initialPosition) : square(initialPosition) {}
        void movePiece(int position);
        int getPosition();
        friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
    private:
        int square;
};