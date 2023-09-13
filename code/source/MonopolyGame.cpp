#include "MonopolyGame.hpp"

MonopolyGame::MonopolyGame(std::initializer_list<IPlayer> il) {
        players.reserve(8);
        for(const auto& it: il)
            addPlayer(it);

        board.resize(40);
        board[0] = TYPEOFSQUARE::START;

        for(int i = 1; i < board.size(); i++)
            board[i] = TYPEOFSQUARE::PENALTY;
}

void MonopolyGame::addPlayer(const IPlayer& player) {
    players.push_back(std::make_shared<IPlayer>(player));
}

void MonopolyGame::startGame() {
    checkConstrains();

    for(int currPlayerIterator = 0; (players.size() != 1); currPlayerIterator = (currPlayerIterator + 1) % players.size()) {
        std::shared_ptr<IPlayer> accPlayer = players[currPlayerIterator];
        
        int dices = throwDices();
        int currentPlayerPosition = accPlayer->getPosition();

        if(currentPlayerPosition + dices > 40) accPlayer->receiveMoney(10);

        accPlayer->movePlayer(dices);
        int final_position = accPlayer->getPosition();

        if(board[final_position] == TYPEOFSQUARE::PENALTY)  accPlayer->receiveMoney(-10);

        if(board[final_position] == TYPEOFSQUARE::REWARD) accPlayer->receiveMoney(10);


        if(accPlayer->getMoney() < 0) losePlayer(accPlayer);

        printGame();
    }

    std::cout << "\nGracz: " << *players.front() << " Wygral Gra!";
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

int MonopolyGame::throwDices() const {
    int kostkaPierwsza = std::rand() % 6 + 1;
    int kostkaDruga = std::rand() % 6 + 1;
    return kostkaPierwsza + kostkaDruga;
}

void MonopolyGame::losePlayer(playerT player) {
        players.erase(std::remove(players.begin(), players.end(), player), players.end());
        lostPlayers.push_back(player);
}



