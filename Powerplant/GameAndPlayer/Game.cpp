
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

