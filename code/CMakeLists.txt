add_executable(program main.cpp
        includes/Player.hpp
        source/Player.cpp
        includes/Piece.hpp
        source/Piece.cpp
        source/MonopolyGame.cpp
        includes/MonopolyGame.hpp
        source/Square.cpp
        includes/Square.hpp
        includes/IEvent.hpp
        includes/Events.hpp
        includes/ID.hpp
        source/ID.cpp
)

include_directories(includes)