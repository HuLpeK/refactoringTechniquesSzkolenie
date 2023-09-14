#include "../includes/BoardIterator.hpp"


Square& BoardIterator::next(){
    currentIndex = (currentIndex+1)%board.getSize();

    return board.at(currentIndex);
}

Square& BoardIterator::get(){
    return board.at(currentIndex);
}

