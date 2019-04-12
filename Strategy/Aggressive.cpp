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

void Aggressive::buyCities(Map *map, Player* p, int gamePhaseNumber) {
    //DECLARE VARIABLES
    int connectionCost = 0;
    std::string userIn;
    Vertex houseBuildingLocation;
    bool validEntry;
    bool houseAvailableAtLocation;
    vector<std::string> nameOfPlayerCities;
    vector<std::string> nameOfMapCities;
    vector<Vertex> existingCities = map->getVertices();

    //START LOOP FOR THE PLAYER BUILDING PHASE
    while (true) {
        //Update booleans for iteration
        validEntry = false;
        std::cout << "STARTING playerTurn LOOP for " << p->getPlayerName() << "\n";
        //START LOOP FOR VALID INPUT
        while (!validEntry) {
            //DISPLAY MAP AND AVAILABLE CITIES
            cout << "Now displaying map\n" << *map << "\n";
            if (!p->getStartedNetwork())
                cout << p->getPlayerName() << " your network is currently empty\nYou can start your city anywhere available\n";
            else {
                //Display player network
                std::cout << "Now displaying " << p->getPlayerName() << "'s network:\n";
                for (int i = 0; i < p->getMyHouses().size(); i++)
                    std::cout << "House #" << i << " located at: " << p->getMyHouses().at(i) << "\n";
            }//close else, player already started network

            //PROMPT PLAYER TO SELECT CITY
            std::cout << p->getPlayerName()
                      << ", please enter the name of the city that you would like to add to your network, or type PASS to continue\n";
            std::cin >> userIn;
            if (userIn == "PASS") {
                cout << "\n" << p->getPlayerName() << " has selected to pass\n";
                return;
            }//close if player selects PASS
            else {
                std::cout << "Debug 1 - entered else, not PASS\n";
                //ENTER VALIDATE AND RE-SELECT
                //VALIDATE SELECTION	--> Validate that the vertex exists, if new network, validate that its not owned
                //Validation 1 - Existence of vertex with that name
                for (auto & existingCitie : existingCities)
                    if (existingCitie.getName() == userIn) {
                        validEntry = true;
                        std::cout
                                << "\nThe vertex entered has passed the 1st verification test, because it exists on the map\n";
                    }//close if valid entry found
                if (!validEntry)
                    std::cout << "\nThe vertex entered is invalid, because it does not exist on the map\n";

                //Validation 2 - player does not own that city and it is available
                if (validEntry && p->getStartedNetwork()) {
                    //Make invalid if a match is already found
                    for (const auto & myHouse : p->getMyHouses())
                        if (myHouse == userIn) {
                            validEntry = false;
                            std::cout << "\nError - " << p->getPlayerName() << " already owns the vertex " << userIn << "\n";
                        }//close if found player owns a house at this vertex/city
                }//close if vertex exists and network has been started

            }//close else player selects a City(Vertex)
        }//close while invalidEntry loop

        //CALCULATE CONNECTION COST --> CHECK IF FIRST CITY HAS BEEN SELECTED, IF NO, CONNECTION COST = 0
        if (!p->getStartedNetwork())
            connectionCost = 0;
        else {
            std::vector<int> shortestPathToAllVertices;
            for (const auto & myHouse : p->getMyHouses())
                //Get the shortest path from the user selected city to all other cities in the network
                shortestPathToAllVertices.push_back(map->shortestPath(userIn, myHouse));
            std::sort(shortestPathToAllVertices.begin(), shortestPathToAllVertices.end());
            connectionCost = shortestPathToAllVertices.at(0);
        }//else get the shortest path between the vertex given and
        std::cout << "The connection cost to his city is: " << connectionCost << std::endl;

        //GET HOUSE COST AND ADD TO TOTAL
        int totalCost = (connectionCost + map->findVertex(userIn).getCost());
        std::cout << "The total cost to build a house at this city is: " << totalCost << std::endl;
        std::cout << p->getPlayerName() << " has " << p->getElektros() << std::endl;

        //VALIDATE THAT NO OTHER PLAYER IS ALREADY AT THIS LOCATION
        //Vertex v = map->findVertex(userIn);
        houseAvailableAtLocation = Map::canBuildHouse(map->findVertex(userIn), gamePhaseNumber);
        cout << "\nHouse available at this location? " << houseAvailableAtLocation << "\n";

        //VALIDATE THAT PLAYER HAS ENOUGH ELEKTROS
        if (totalCost > p->getElektros()) {
            std::cout << p->getPlayerName() << " does not have enough elektros to purchase a house at the location: " << userIn
                      << "\n";
            std::cout << p->getPlayerName() << " has " << p->getElektros() << " the total cost to build at location: " << userIn
                      << " is " << totalCost;
        }//if player does not have enough elektros

        if (!houseAvailableAtLocation)
            std::cout << "\nCan not Build at this location, there is already a house here\n";

        if (totalCost <= p->getElektros() && houseAvailableAtLocation) {
            std::cout << p->getPlayerName() << " has built a house in " << userIn << "\n";
            //UPDATE ALL OBJECTS - VERTEX, NUMOFCITIES, Player.numOfCities, Player.myHouses, HOUSE OBJECT?
            std::cout << "Debug A\n";
            p->setElektros(p->getElektros() - totalCost);
            std::cout << "Debug B\n";
            std::cout << "B1 - Display vertex below - map->findVertex( userIn ).getName(): \n";
            std::cout << map->findVertex(userIn).getName() << std::endl;
            string nameOfNewHouseLocation = map->findVertex(userIn).getName();
            std::cout << "B2.... \n";
            std::cout << nameOfNewHouseLocation << "\n";
            std::cout << "B3.... \n";
            p->addHouse(nameOfNewHouseLocation);    // <--- Program exits here
            std::cout << "Debug C\n";
            p->setNumOfCities(p->getNumOfCities() + 1);
            std::cout << "Debug D\n";
            map->findVertexP(userIn)->setPlayer(p->getPlayerName());
            std::cout << "Debug E\n";
            p->setStartedNetwork(true);
            std::cout << "Debug F\n";
        }//close else, player has added this city to his network
        std::cout << "Debug Finish while playerTurn iteration\n";
    }//close while player turn
}
