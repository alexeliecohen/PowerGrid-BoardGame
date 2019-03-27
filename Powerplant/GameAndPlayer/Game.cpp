<<<<<<< HEAD
//
// Created by alext on 2/26/2019.
//

#include <iostream>
#include "Game.h"

Game::Game() {

}

void Game::Phase1() {
    int availablePlayers = numbPlayers;
    int firstPlayerBid;
    string bid;
    do {
        for (int i = 0; i < playerList.size(); ++i) {
            if (playerList[i]->isAuctionReady()) {
                firstPlayerBid = i;
                break;
            }
        }
        cout << playerList[0]->getPlayerName() << "Please enter a number to pick a powerplant" << endl;
//        cin >> bid >>
            cout << pMarket << endl;

//        cout << "Please enter a bid (minimum bid is  "

    } while (availablePlayers > 0);


}
=======
//
// Created by alext on 2/26/2019.
//

#include "Game.h"
using namespace std;
Game::Game() {
//    do {
//        std::cout << "How many players wish to play?" << endl;
//        cin >> numbPlayers;
//        if (numbPlayers<MINNUMBERPLAYERS && numbPlayers > MAXNUMBERPLAYERS) {
//            cout << "Error maxplayers is 6 and minplayers is 2";
//        }
//    }
//    while (numbPlayers<MINNUMBERPLAYERS && numbPlayers > MAXNUMBERPLAYERS);
//    for (int i = 0; i < numbPlayers; ++i) {
//        playerList.push_back(new Player())

    }



//};

>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2
