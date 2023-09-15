

#pragma once

class Square;
class Board;
class BoardIterator;
class Piece;

#include "ID.hpp"

#include <string>
#include <iostream>
#include <utility>
#include <memory>
#include <vector>

#define STARTINGPOSTION 0

class Player : public std::enable_shared_from_this<Player>{
public:
    Player(std::string playerName, std::shared_ptr<Board> bi);

    void performMove(int diceRolled);

    void receiveMoney(int amountOfMoney);

    bool decideToBuy();
    
    bool operator==(const Player& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& player);

    using ptr = std::shared_ptr<Player>;
    [[nodiscard]] int getMoney() const;
private:
    void handleMovingThroughStart(int startingPosition);
    void move(int pos);
    void moveForwardByOne();
    int getPosition();

    bool isPlayerBankrupt() const;
    std::shared_ptr<Board> board;
    std::shared_ptr<BoardIterator> boardIterator;

    std::shared_ptr<Piece> piece;
    int money {100};
    const std::string name {};
    ID playerID; //todo: powtorzenieTypu
};