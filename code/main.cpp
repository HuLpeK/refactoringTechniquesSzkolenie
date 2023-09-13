#include<iostream>

#include "includes/Player.hpp"
#include "includes/Piece.hpp"

int main(){
    Player Hubert("Hubert");
    std::cout << Hubert << '\n';
    
    Piece piece(10);
    std::cout<< piece << "\n";
}