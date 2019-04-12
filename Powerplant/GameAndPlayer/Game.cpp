//
// Created by alext on 2/26/2019.
//

#include <iostream>
#include "Game.h"
#include "../../FileReader/MapLoader.h"
#include "../../Strategy/Normal.h"
#include "../../Strategy/Environmentalist.h"
#include "../../Strategy/Aggressive.h"

Game::Game() {
    Player *p2 = new Player("Mike", new Normal());
    Player *p3 = new Player("Hubert", new Normal());
    Player *p4 = new Player("Marc", new Normal());
    Player *p1 = new Player("Alex", new Normal());
    playerList.push_back(p1);
    playerList.push_back(p2);
    playerList.push_back(p3);
    playerList.push_back(p4);
    numbPlayers = playerList.size();
    myDeck.shuffle();
    p1->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p1->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p2->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p2->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p3->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p3->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p4->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    p4->addPowerplant(*dynamic_cast<Powerplant*>(myDeck.removeCard()));
    for (auto & i : playerList) {
        i->addCoal(20);
        i->addGarbage(20);
        i->addOil(20);
        i->addUranium(20);
    }
    p1->setNumOfCities(2);
    p2->setNumOfCities(3);
    p3->setNumOfCities(4);
    p4->setNumOfCities(5);
    rMarket = new ResourceMarket();
    m = Map::Instance();
    currentBidder = nullptr;
}

std::vector<Player*> Game::getPlayerList() {
    return playerList;
}

int Game::getNumPlayers() {
    return numbPlayers;
}

void Game::DeterminePlayerOrder() {
    //sort in reverse order biggest to smallest
    sort(playerList.begin(), playerList.end());
    reverse(playerList.begin(), playerList.end());
}

 bool Game::isValidInteger(const std::string& line) {
    char *p;
    //convert string to long of base 10
    strtol(line.c_str(), &p, 10);
    //check if the pointer is a number if ==0, then not a number
    return *p == 0;
}

bool Game::canAffordPowerplant() {
    //if the player does not have enough money to afford the powerplant
    if (currentBid.getBidValue() >= currentBidder->getElektros()) {
        cout << endl << currentBidder->getPlayerName()
             << " cannot afford to pay the current bid for the powerplant player, has "
             << "been ejected from this round" << endl;
        return false;
    }
    return true;
}

bool Game::Pass(string &msg, bool passAuction) {
    char skip;
    do {
        cout << msg; //output the message to the user
        cin >> skip; //decision made by user
        skip = tolower(skip); //convert to lower case
        if (skip == 'y') {
            //if the player wants to skip the auction set both variables roundReady and auction ready to
            // false
            if (passAuction) {
                currentBidder->setRoundReady(false);
                currentBidder->setAuctionReady(false);
            }
                //otherwise just skip the round
            else {
                currentBidder->setRoundReady(false);
            }
            return true;
        }
            //player doesnt want to skip the round or the auction
            //then just keep going
        else if (skip == 'n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
            //otherwise the player entered an invalid entry
        else {
            cout << endl << "error invalid entry" << endl;
            //clear the cin buffer of other characters if there are any
            //and restart the loop
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

bool Game::canBid() {
    //if the player cannot afford a powerplant
    if (!canAffordPowerplant()) {
        return false;
    }
        //If the player has already bought a powerplant or decided to skip the auction.
    else if (!currentBidder->isAuctionReady()) {
        cout << "Player " << currentBidder->getPlayerName() << " has already bought a powerplant" << endl;
        return false;
    }
        //player decided to skip the round instead
    else if (!currentBidder->isRoundReady()) {
        cout << "Player " << currentBidder->getPlayerName() << " has decided to skip the round" << endl;
        return false;
    } else {
        return true;
    }
}

bool Game::skipAuction() {
    //send message and skip the round option
    string msg = currentBidder->getPlayerName() + " Would you like to skip this auction enter Y(yes) or N(no)?";
    return Pass(msg, true);
}


bool Game::SkipRound() {
    //send message and dont skip the round option
    string msg = currentBidder->getPlayerName() + "Would you like to skip this round enter Y(yes) or N(no)?";
    return Pass(msg, false);
}


Game::~Game() {
    //delete playerlist pointers
    for (auto & i : playerList) {
        delete i;
    }
    delete rMarket;
    delete m;
    //set currentBidder to NULL
    //currentBidder = NULL;
    delete currentBidder;
}

void Game::Phase1() {
    int mapFile = 0;
    int numPlayers = 0;
    int regionNumber = 0;
    string path = "../MapFiles/";
    std::vector<string> files = std::vector<string>();
    std::vector<Player> players = std::vector<Player>();
    std::vector<string> regionsUsed;

    std::cout << "----------------------------------------\n";
    std::cout << "          WELCOME TO POWERGRID!!        \n";
    std::cout << "----------------------------------------\n";

    std::cout << "\nPlease enter the number of the map you would like to play: \n";
    cout << "1) file\n";
    cout << "2) mapFile.txt\n";
    cout << "3) test2.txt\n";
    cin >> mapFile;
    //Loading a map
    MapLoaderB ml = MapLoaderB();
    if(mapFile == 1) {
        m = MapLoaderB::buildMapB("../MapFiles/file");
    }
    else if(mapFile == 2) {
        m = MapLoaderB::buildMapB("../MapFiles/mapFile.txt");
    }
    else if(mapFile == 3) {
        m = MapLoaderB::buildMapB("../MapFiles/test2.txt");
    }
    //printing the loaded map
    cout << *m;
    std::vector<string> regions = m->getRegions();
    cout << "Please enter the number of players(2-6): ";
    cin >> numPlayers;
    for(int j = 0; j < numPlayers; j++) {
        auto *p = new Player();
        players.push_back(*p);
        cout << "Please select a region: \n";
        for(int k = 0; k < regions.size(); k++) {
            cout << k + 1 << ") " << regions[k] << "\n";
        }
        cin >> regionNumber;
        for(const string& r : regions) {
            if(m->checkAdjacentRegions(regions.at(regionNumber - 1), r) || regionsUsed.empty()) {
                regionsUsed.push_back(regions.at(regionNumber - 1));
                regions.erase(regions.begin()+ regionNumber - 1);
                break;
            }
            else {
                cout << "Please pick a region adjacent to the others\n";
                break;
            }
        }
    }
    m->createFinalMap(regionsUsed);
    for(const string& s : m->getRegions()) {
        cout << s << "\n";
    }

    Deck d = Deck();
    std::cout << d << "\n\n";
    d.shuffle();
    std::cout << d;
    ResourceMarket rmarket = ResourceMarket();
    PowerplantMarket pmarket = PowerplantMarket(d);
    cout << pmarket;
}

void Game::Phase2() {
    //Determine the player order here by sorting the vector of values
    DeterminePlayerOrder();
    //this number is initially set to the number of players in the list
    //this checks if all the players can participate in phase 1, if not this
    //value will reach 0
    int phaseOnePlayersRemaining = numbPlayers;

    int oneRemainingPlayer = 1;
    int NoAvailablePlayers = 0;

    //this value is set to the number of available players,tells us when all the players have finished the round
    //when this value reaches 0
    int auctionRoundPlayersRemaining;

    //startNewBidIndex is the next player in the list to start the bid round on the next powerplant
    //currentBidder is the index for next player to participate in the round bid for the selected powerplant
    int startNewBidIndex = 0, currentRoundBidderIndex, mostRecentBidIndex;

//while there are still players that can/want to auction
    while (phaseOnePlayersRemaining > NoAvailablePlayers) {
        //loop through the player list starting from the beginning
        currentBidder = playerList[startNewBidIndex];
        //If Player has bought a powerplant or doesnt want to auction then skip
        if (!currentBidder->isAuctionReady()) {
            startNewBidIndex = (startNewBidIndex + 1) % numbPlayers;
            continue;
        }

        //if the player decides to skip phase 1 entirely then move forward to the next player
        if (skipAuction()) {
            phaseOnePlayersRemaining--;
            continue;
        }
        //number of players to start the round
        auctionRoundPlayersRemaining = phaseOnePlayersRemaining;

        currentBidder->executeAuction(this, currentBidder);
        currentRoundBidderIndex = startNewBidIndex;
        mostRecentBidIndex = currentBidder->Bid(this, currentBidder, currentRoundBidderIndex, auctionRoundPlayersRemaining, oneRemainingPlayer);
        currentBidder = playerList[mostRecentBidIndex];
        cout << endl << currentBidder->getPlayerName() << " has won this bidding round and has received " << endl
             << currentBid << endl
             << "he will not be able to participate in the rest of the phase" << endl;
        //The last remaining player to have placed a bid is wins the powerplant, so
        //add the powerplant, remove the bid value, and player can no longer participate in
        //auction
        currentBidder->addPowerplant(currentBid);
        currentBidder->removeElektro(currentBid.getBidValue());
        currentBidder->setAuctionReady(false);
        phaseOnePlayersRemaining--;
    }//end phase1 while loop
    cout << endl << "All players have either skipped or purchases a powerplant, Phase 1 Terminated" << endl;
}

void Game::Phase3() {
    /*
    *  PART 3 ASSIGNMENT 2
    */

    /*
     *  RESOURCE BUYING PHASE
     *  requires a resource market and players --> hard-coded below
     */

    std::cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout<<"\nWELCOME TO POWER GRID PHASE 3\n";
    std::cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout<<"\nCREATING OBJECTS FOR PHASE 3 OF ASSIGNMENT 2\n";
    std::cout<<"\nCREATING 2 PLAYERS, player1 & player2\n";

    //Create Map
    MapLoaderB mapLoaderPart3 = MapLoaderB();
    Map* mapPhase3 = MapLoaderB::buildMapB("../MapFiles/file");
    std::cout<<"\nThe map has been created for phase 3\n";

    //Give Power Plants To Player 2
    std::cout<<"\nPowerplants for player2 are being placed into his/her possesion for demoing's Part 3, buying resources\n";

    for (auto & i : playerList)
        i->buyResources( rMarket );

    /*
     *  HOUSE BUILDING PHASE
     *  requires a map, resource market and players --> hard-coded below
     */

    //gamePhase: 1
    for (auto & i : playerList)
        i->buyCities( mapPhase3, 1 );

    /*
     *  END OF PART 3 ASSIGNMENT 2
     */
}

/**
 * Method phase 4, powering cities by using resources and power plants to generate elecktro
 */
void Game::Phase4() {
    //bureaucracy
    for (Player *p : playerList)
        p->powerCities();

    //replace powerplants
    pMarket.replaceFutureMarket(myDeck);
    cout << pMarket << endl;
    //replace resourcemarket
    rMarket->resupplyMarket(numbPlayers,1);
    cout << pMarket << endl;
}
//end method
