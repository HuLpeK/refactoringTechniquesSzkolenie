#include "../includes/BoardIterator.hpp"


Square& BoardIterator::next(){
    currentIndex = (currentIndex+1)%board->getSize();
    piece->movePiece(1);
    return board->at(currentIndex);
}

Square& BoardIterator::get(){
    return board->at(currentIndex);
}
