#include "../includes/Board.hpp"


Square& Board::at(int position){
    return squares[position];
}

Board::Board(const int size) : number_of_squares(size), start_square(0){
    squares.resize(number_of_squares);
    squares[start_square].addActionOnPassby(std::make_shared<Actions::Start>());
}

int Board::getSize(){
    return squares.size();
}
