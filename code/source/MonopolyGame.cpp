#include "MonopolyGame.hpp"

MonopolyGame::MonopolyGame(std::initializer_list<Player> il) {
        players.reserve(8);
        for(const auto& it: il)
            addPlayer(it);

        board.resize(40);

        board[0].addEvent(std::make_shared<Events::Start>());

        for(int i = 1; i < 40; i++)
            board[i].addEvent(std::make_shared<Events::Penelty>());

}

void MonopolyGame::addPlayer(const Player& player) {
    players.push_back(std::make_shared<Player>(player));
}

void MonopolyGame::startGame() {
    checkConstrains();

    for(int currPlayerIterator = 0; (players.size() > 1); currPlayerIterator = (currPlayerIterator + 1) % players.size()) {
        processPlayerTurn(currPlayerIterator);
    }

    std::cout << "\nGracz: " << *players.front() << " Wygral Gra!";
}

void MonopolyGame::processPlayerTurn(int currPlayerIterator) {
    std::shared_ptr<Player> actPlayer = players[currPlayerIterator];

    int dices = rollingDice.throwTwoDices();


    actPlayer->movePlayer(dices);

    int finalPosition = actPlayer->getPosition();


    board[finalPosition].processEvents(actPlayer);


    if(isPlayerBankrupt(actPlayer))
        losePlayer(actPlayer);

    printGame();
}

bool MonopolyGame::isPlayerBankrupt(std::shared_ptr<Player> player) {
    return player->getMoney() < 0;
}

bool MonopolyGame::isPassingStart(int start, int end) const{
    return start > end;
}

void MonopolyGame::printGame() {
    std::cout << "==STATUS GRY==\n";
    for(const auto& it: players)
        std::cout << *it << "\n";
    std::cout << "\n\n";
}

void MonopolyGame::checkConstrains() {
    if(players.size() < 2)
        throw std::out_of_range("Amount of players is not sufficient");
    if(players.size() > 8)
        throw std::out_of_range("There is too many players");
}

void MonopolyGame::losePlayer(Player::ptr player) {
        players.erase(std::remove(players.begin(), players.end(), player), players.end());
        lostPlayers.push_back(player);
}



