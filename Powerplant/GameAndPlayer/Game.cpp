//
// Created by alext on 2/26/2019.
//

#include <iostream>
//#include <w32api/commctrl.h>
#include "Game.h"
#include "../../FileReader/MapLoader.h"

Game::Game() {
    Player *p1 = new Player("Alex");
    Player *p2 = new Player("Mike");
    Player *p3 = new Player("Hubert");
    Player *p4 = new Player("Marc");
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
//    for (int i = 0; i <playerList.size(); ++i) {
//        playerList[i]->addCoal(20);
//        playerList[i]->addGarbage(20);
//        playerList[i]->addOil(20);
//        playerList[i]->addUranium(20);
//    }
    p1->setNumOfCities(2);
    p2->setNumOfCities(3);
    p3->setNumOfCities(4);
    p4->setNumOfCities(5);
    rMarket = new ResourceMarket();
}


void Game::DeterminePlayerOrder() {
    //sort in reverse order biggest to smallest
    sort(playerList.begin(), playerList.end());
    reverse(playerList.begin(), playerList.end());
}

 bool Game::isValidInteger(std::string line) {
    char *p;
    //convert string to long of base 10
    strtol(line.c_str(), &p, 10);
    //check if the pointer is a number if ==0, then not a number
    return *p == 0;
}


void Game::Auction() {
    string bid;
    int marketSize = pMarket.getSize();
    do {
        cout << currentBidder->getPlayerName() << "Please enter a number to pick a powerplant" << endl;
        cout << pMarket << endl;
        cin >> bid;
        //if the input was not a valid integer,or the number picked was larger/less than the powerplant size
        //output error clear buffer and restart.
        if (!isValidInteger(bid) || stoi(bid) > marketSize || stoi(bid) < 0) {
            cout << "Error: Entered wrong value for bid, please enter a correct powerplant number" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValidInteger(bid) || stoi(bid) > marketSize - 1 || stoi(bid) < 0);
    int val = stoi(bid);
    currentBid = pMarket.removePowerplant(val);
    cout << currentBid << endl;
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
    } while (skip != 'y' || skip != 'n');
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

bool Game::Bid() {
    string bid;
    do {
        cout << "Current Bid for the Powerplant " << currentBid.getBidValue() << " elektro" << endl
             << "You have " << currentBidder->getElektros() << " elektro available: ";
        //enter the bid
        cin >> bid;
        //if the bid is not a valid number report error
        if (!isValidInteger(bid)) {
            cout << "Not a valid number, please enter a number";
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

            //if the bid the player entered is greater than the number of elektros a player owns report error
        else if (stoi(bid) > currentBidder->getElektros() || stoi(bid) < 0 || stoi(bid) < currentBid.getBidValue()) {
            cout << "You entered " << stoi(bid) << " elektro,You only have " << currentBidder->getElektros() << endl;
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            currentBid.setBidValue(stoi(bid));
            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
    } while (true);
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
    for (int i = 0; i < playerList.size(); ++i) {
        delete playerList[i];
    }
    //set currentBidder to NULL
    currentBidder = NULL;
}

void Game::Phase1() {
    //    int i = 1;
    int mapFile = 0;
    int numPlayers = 0;
    int regionNumber = 0;
    string path = "../MapFiles/";
    std::vector<string> files = std::vector<string>();
    std::vector<Player> players = std::vector<Player>();
    std::vector<string> regionsUsed;
    Map* map = Map::Instance();

    std::cout << "----------------------------------------\n";
    std::cout << "          WELCOME TO POWERGRID!!        \n";
    std::cout << "----------------------------------------\n";

    std::cout << "\nPlease enter the number of the map you would like to play: \n";
//    for (const auto& entry : std::experimental::filesystem::directory_iterator(path)) {
//        files.push_back(entry.path().string());
//        std::cout << i << ") " << entry.path().string().substr(12) << std::endl;
//        i++;
//    }
    cout << "1) file\n";
    cout << "2) mapFile.txt\n";
    cout << "3) test2.txt\n";
    cin >> mapFile;
    //Loading a map
    MapLoaderB ml = MapLoaderB();
    if(mapFile == 1) {
        map = ml.buildMapB("../MapFiles/file");
    }
    else if(mapFile == 2) {
        map = ml.buildMapB("../MapFiles/mapFile.txt");
    }
    else if(mapFile == 3) {
        map = ml.buildMapB("../MapFiles/test2.txt");
    }
    m = map;
    //Map m = ml.buildMapB(files.at(mapFile - 1));
    //printing the loaded map
    cout << *map;
    std::vector<string> regions = map->getRegions();
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
            if(map->checkAdjacentRegions(regions.at(regionNumber - 1), r) || regionsUsed.empty()) {
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
    map->createFinalMap(regionsUsed);
    for(const string& s : map->getRegions()) {
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

    //used for bidding for a powerplant
    //if the value reaches 1 then the remaining bidder gets the plant
    int marketSize = pMarket.getSize();

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

        Auction();
        currentRoundBidderIndex = startNewBidIndex;

        //Player that chooses powerplant starts a bid
        Bid();
        //store the player as a the most recent bid
        mostRecentBidIndex = currentRoundBidderIndex;

        //while there is still more than one player left
        while (auctionRoundPlayersRemaining > oneRemainingPlayer) {
            //next bidder for the round
            currentBidder = playerList[currentRoundBidderIndex];

            //if the current player has already bought a powerplant,or has decided to pass on current bid
            //then go to next player

            //if the current player has already bought the powerplant or has decided to skip
            //the round/auction
            if (!canBid()) {
                auctionRoundPlayersRemaining--;
                currentRoundBidderIndex = (currentRoundBidderIndex + 1) % numbPlayers;
                continue;
            }
                //The player decides to skip the reound decrement the players available to play this round and continue;
            else if (SkipRound()) {
                auctionRoundPlayersRemaining--;
                currentRoundBidderIndex = (currentRoundBidderIndex + 1) % numbPlayers;
                continue;
            }
            Bid();

            //The last bidder to have bid for the poweprlant is stored just in case
            //we reach only one player, then the loop is terminated
            mostRecentBidIndex = currentRoundBidderIndex;

            //go to the next bidder in the player list
            currentRoundBidderIndex = (currentRoundBidderIndex + 1) % numbPlayers;
        }//end of Round
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

    //Create Players
    std::vector<Player> playersPhase3 = std::vector<Player>();
    Player p1 = Player( "player1" );
    Player p2 = Player( "player2" );
    playersPhase3.push_back( p1 );
    playersPhase3.push_back( p2 );
    //Create Map
    MapLoaderB mapLoaderPart3 = MapLoaderB();
    Map* mapPhase3 = mapLoaderPart3.buildMapB("../MapFiles/file");
    std::cout<<"\nThe map has been created for phase 3\n";

    //Create Resource Market
    //auto resMarket = new ResourceMarket();

    //Give Power Plants To Player 2
    std::cout<<"\nPowerplants for player2 are being placed into his/her possesion for demoing's Part 3, buying resources\n";


    for ( int i = 0 ; i < playerList.size() ; i++ )
        playerList.at(i)->buyResources( rMarket );

    /*
     *  HOUSE BUILDING PHASE
     *  requires a map, resource market and players --> hard-coded below
     */

    //Source of input parameters above
    //map: m
    //gamePhase: 1
    for ( int i = 0 ; i < playerList.size() ; i++ )
        playerList.at(i)->buyCities( mapPhase3, 1 );

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
