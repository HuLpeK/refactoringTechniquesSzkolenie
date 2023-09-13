#include "../includes/Piece.hpp"


std::ostream& operator<<(std::ostream &out, const Piece &piece) {
    out << "Pozycja: " << piece.square;
    return out;
}

void Piece::movePiece(int position){
    square = (square + position)%40; //TODO: magic number
}

int Piece::getPosition() {
    return square;
}
