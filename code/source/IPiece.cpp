#include "../includes/IPiece.hpp"


std::ostream& operator<<(std::ostream &out, const IPiece &piece) { 
    out << "Pozycja: " << piece.square;
    return out;
}