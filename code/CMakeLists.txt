add_executable(program main.cpp
        includes/IPlayer.hpp
        source/IPlayer.cpp
        source/Player.cpp
        includes/Player.hpp
        includes/IPiece.hpp
        source/IPiece.cpp
        source/Piece.cpp
        includes/Piece.hpp
        source/MonopolyGame.cpp
        includes/MonopolyGame.hpp
)

include_directories(includes)