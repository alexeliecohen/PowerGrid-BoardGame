//
// Created by Hubert on 4/11/2019.
//

#include <PowerplantMarket.h>
#include <climits>
#include "Aggressive.h"

void Aggressive::executeAuction(Game* g, Player* p) {
    std::string bid;
    int marketSize = g->pMarket.getSize();
    int maxPriority = 0;
    int maxPriorityIndex = -1;
    int i;
    do {
        cout << p->getPlayerName() << " Please enter a number to pick a powerplant" << endl;
        cout << g->pMarket << endl;
//        cin >> bid;
        for(i = 0; i < g->pMarket.getCurrentMarket().size(); i++) {
            if(g->pMarket.getCurrentMarket().at(i).getPriority() > maxPriority) {
                maxPriorityIndex = i;
                maxPriority = g->pMarket.getCurrentMarket().at(i).getPriority();
            }
        }
        bid = std::to_string(maxPriorityIndex);
        //if the input was not a valid integer,or the number picked was larger/less than the powerplant size
        //output error clear buffer and restart.
        if (!Game::isValidInteger(bid) || stoi(bid) > marketSize || stoi(bid) < 0) {
            cout << "Error: Entered wrong value for bid, please enter a correct powerplant number" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!Game::isValidInteger(bid) || stoi(bid) > marketSize - 1 || stoi(bid) < 0);
    int val = stoi(bid);
    g->currentBid = g->pMarket.removePowerplant(val);
    cout << g->currentBid << endl;
}

bool Aggressive::executeBid(Game *g) {
    string bid;
    do {
        cout << "Current Bid for the Powerplant " << g->currentBid.getBidValue() << " elektro" << endl
             << "You have " << g->currentBidder->getElektros() << " elektro available: ";
        //enter the bid
        if(g->currentBid.getBidValue() <= g->currentBid.getPriceCost()) {
            bid = std::to_string(g->currentBid.getPriceCost());
        }
        else {
            bid = std::to_string(g->currentBid.getBidValue() + 1);
        }
        cout << bid << endl;
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
            return true;
        }
    } while (true);
}

int Aggressive::Bid(Game* g, Player* p, int currentRoundBidderIndex, int auctionRoundPlayersRemaining, int oneRemainingPlayer) {
    int mostRecentBidIndex;
    //Player that chooses powerplant starts a bid
    g->currentBidder->executeBid(g);
    //store the player as a the most recent bid
    mostRecentBidIndex = currentRoundBidderIndex;

    //while there is still more than one player left
    while (auctionRoundPlayersRemaining > oneRemainingPlayer) {
        //next bidder for the round
        g->currentBidder = g->getPlayerList()[currentRoundBidderIndex];

        //if the current player has already bought a powerplant,or has decided to pass on current bid
        //then go to next player

        //if the current player has already bought the powerplant or has decided to skip
        //the round/auction
        if(g->currentBidder->getPlayerName() != p->getPlayerName()) {
            if (!g->canBid()) {
                auctionRoundPlayersRemaining--;
                currentRoundBidderIndex = (currentRoundBidderIndex + 1) % g->getNumPlayers();
                continue;
            }
                //The player decides to skip the reound decrement the players available to play this round and continue;
            else if (g->SkipRound()) {
                //auctionRoundPlayersRemaining--;
                currentRoundBidderIndex = (currentRoundBidderIndex + 1) % g->getNumPlayers();
                continue;
            }
        }
        std::cout << g->currentBidder->getPlayerName() << "'s turn to bid\n";
        g->currentBidder->executeBid(g);

        //The last bidder to have bid for the poweprlant is stored just in case
        //we reach only one player, then the loop is terminated
        mostRecentBidIndex = currentRoundBidderIndex;

        //go to the next bidder in the player list
        currentRoundBidderIndex = (currentRoundBidderIndex + 1) % g->getNumPlayers();
    }//end of Round
    return mostRecentBidIndex;
}
