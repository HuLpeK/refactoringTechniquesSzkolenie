#include "../includes/IPiece.hpp"


std::ostream& operator<<(std::ostream &out, const IPiece &piece) { 
    out << "Pozycja: " << piece.square;
    return out;
}

void IPiece::movePiece(int position){
    square = (square + position)%40; //TODO: magic number
}

int IPiece::getPosition() {
    return square;
}
