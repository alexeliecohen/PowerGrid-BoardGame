//
// Created by Hubert on 4/11/2019.
//

#include <PowerplantMarket.h>
#include "Aggressive.h"

void Aggressive::executeAuction(Game* g, Player* p) {
    std::string bid;
    PowerplantMarket pMarket = g->pMarket;
    int marketSize = pMarket.getSize();
    do {
        cout << p->getPlayerName() << " Please enter a number to pick a powerplant" << endl;
        cout << pMarket << endl;
        cin >> bid;
        //if the input was not a valid integer,or the number picked was larger/less than the powerplant size
        //output error clear buffer and restart.
        if (!Game::isValidInteger(bid) || stoi(bid) > marketSize || stoi(bid) < 0) {
            cout << "Error: Entered wrong value for bid, please enter a correct powerplant number" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!Game::isValidInteger(bid) || stoi(bid) > marketSize - 1 || stoi(bid) < 0);
    int val = stoi(bid);
    g->currentBid = pMarket.removePowerplant(val);
    cout << g->currentBid << endl;
}

bool Aggressive::executeBid(Game *g, Player *p) {
    string bid;
    do {
        cout << "Current Bid for the Powerplant " << g->currentBid.getBidValue() << " elektro" << endl
             << "You have " << g->currentBidder->getElektros() << " elektro available: ";
        //enter the bid
        cin >> bid;
        //if the bid is not a valid number report error
        if (!Game::isValidInteger(bid)) {
            cout << "Not a valid number, please enter a number";
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

            //if the bid the player entered is greater than the number of elektros a player owns report error
        else if (stoi(bid) > g->currentBidder->getElektros() || stoi(bid) < 0 || stoi(bid) < g->currentBid.getBidValue()) {
            cout << "You entered " << stoi(bid) << " elektro,You only have " << g->currentBidder->getElektros() << endl;
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            g->currentBid.setBidValue(stoi(bid));
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
    } while (true);
}
