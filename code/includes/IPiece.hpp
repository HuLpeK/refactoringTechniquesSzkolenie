#pragma once

#include <ostream>

class IPiece{
    public:
        IPiece(int initialPosition) : square(initialPosition) {}
        void movePiece(int position);
        int getPosition();
        friend std::ostream& operator<<(std::ostream& out, const IPiece& piece);
    private:
        int square;
};