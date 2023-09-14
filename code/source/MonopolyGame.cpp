#include "MonopolyGame.hpp"

MonopolyGame::MonopolyGame(std::initializer_list<std::string> il) : board(std::make_shared<Board>(40)){
        players.reserve(8);
        for(const auto& it: il)
            addPlayer(it);


    board->at(0).addActionOnStep(std::make_shared<Actions::Start>());

        for(int i = 1; i < 40; i++)
            board->at(i).addActionOnStep(std::make_shared<Actions::Penelty>());

}

void MonopolyGame::addPlayer(const std::string &playerName) {
    players.push_back(std::make_shared<Player>(playerName, BoardIterator(*board)));
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

    try{
        actPlayer->performMove(rollingDice.throwTwoDices());
    }catch(...){
        losePlayer(actPlayer);
    }

    printGame();
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



