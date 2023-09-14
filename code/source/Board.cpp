#include "../includes/Board.hpp"


Square& Board::at(int position){
    return squares[position];
}