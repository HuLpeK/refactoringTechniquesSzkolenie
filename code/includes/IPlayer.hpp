

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

#define STARTINGPOSITION 0

class IPlayer : public std::enable_shared_from_this<IPlayer>{
public:
    IPlayer(std::string playerName, std::shared_ptr<Board> bi);

    void performMove(int diceRolled);

    [[nodiscard]] int getMoney() const;

    void receiveMoney(int amountOfMoney);

    bool decideToBuy();

    bool operator==(const IPlayer& lhs) const;

    friend std::ostream& operator<<(std::ostream& out, const IPlayer& player);
    using ptr = std::shared_ptr<IPlayer>;
private:
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