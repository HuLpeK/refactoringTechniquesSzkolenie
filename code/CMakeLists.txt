add_executable(program main.cpp
        includes/IPlayer.hpp
        source/IPlayer.cpp
        includes/Piece.hpp
        source/Piece.cpp
        source/MonopolyGame.cpp
        includes/MonopolyGame.hpp
        source/Square.cpp
        includes/Square.hpp
        includes/IAction.hpp
        includes/Actions.hpp
        includes/ID.hpp
        source/ID.cpp
        source/Dice.cpp
        includes/Dice.hpp
        source/Board.cpp
        includes/Board.hpp
        source/BoardIterator.cpp
        includes/BoardIterator.hpp
)

include_directories(includes)