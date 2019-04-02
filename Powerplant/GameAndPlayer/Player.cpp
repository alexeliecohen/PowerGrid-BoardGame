/*
 * Player.cpp
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 445
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 *
 */

#include "Player.h"
#include "../../Map/Vertex.h"
#include "../../Map/Map.h"
#include <string>
#include <iostream>
#include <locale>
#include "Game.h"

int Player::numOfPlayers = 0;
vector<string> Player::houseColor = {"Green", "Blue", "Black", "Pink", "Yellow", "Orange"};

//ADD THIS ATTRIBUTE TO PLAYER CLASS FOR FLAGGING WETHER NETWORK OF CITIES HAS BEEN STARTED
bool startedNetwork = false;
std::vector<string> myHouses;

//Constructors
/**
 * Player default constructor takes the playername the choice of house color and sets variables to default
 * values at start of the game
 */
Player::Player() {
    //prompt player to enter their name
    cout << "Welcome Player " << numOfPlayers + 1 << "!" << endl;
    //if the player has exceeded 6, then exit
    if (numOfPlayers == MAXNUMBERPLAYERS) {
        std::cout << "Max Number of players reached, cannot create more";
        return;
    }
    //take player name and set to the player
    cout << "Please enter your player name: " << endl;
    cin >> playerName;

    //prompt the player to choose what color house they want
    cout << "Please select a number for a house color:" << endl;
    for (int i = 0; i < houseColor.size(); ++i) {
        cout << i << ":" << houseColor[i] << endl;
    }
    int choice;
    cin >> choice;
    //set house color to player
    myHouseColor = houseColor[choice];
    //erase the choice
    houseColor.erase(houseColor.begin() + choice);
    //set the default for the player
    elektros = DEFAULTELECTRO;
    oil = DEFAULTRESOURCE;
    coal = DEFAULTRESOURCE;
    uranium = DEFAULTRESOURCE;
    garbage = DEFAULTRESOURCE;
    numOfCities = DEFAULTHOME;
    numbHomes = DEFAULTHOME;
    auctionReady = true;
    roundReady = true;
    numOfPlayers++;
    numCities = 0;
}//close constructor

/**
 *
 * @param nameIn parametrized constructor takes name
 */
Player::Player(std::string nameIn) {
    //if they try to add more palyers than the max
    if (numOfPlayers == MAXNUMBERPLAYERS) {
        std::cout << "Max Number of players reached, cannot create more";
        return;
    }
    playerName = nameIn;
    this->myHouseColor = myHouseColor;
    elektros = DEFAULTELECTRO;
    oil = DEFAULTRESOURCE;
    coal = DEFAULTRESOURCE;
    uranium = DEFAULTRESOURCE;
    garbage = DEFAULTRESOURCE;
    numOfCities = DEFAULTHOME;
    numbHomes = DEFAULTHOME;
    auctionReady = true;
    roundReady = true;
    this->numOfPlayers++;
    numCities = 0;
}

Player::~Player() {
    std::cout << "Player " << playerName << " has left the game" << endl;
    numOfPlayers--;
}//close destructor

//Setters and Getters


//ostream &Player::displayHouses(ostream &stream) {
//    for (int i = 0; i < myHouses.size(); ++i) {
//        stream << myHouses[i] << endl;
//    }
//    return stream;
//}


ostream &operator<<(ostream &stream, Player &Object) {
    //Output the player contents to the stream
    stream << "Player Name: " << Object.playerName << "\n" << "# Electros: " << Object.elektros << "\n"
           << "Total # Resources: " << Object.oil + Object.coal + Object.garbage + Object.uranium << "\n" << "# Oil: "
           << Object.oil << "\n"
           << "Coal: " << Object.coal << "\n" << "Garbage: " << Object.garbage << "\n" << "Uranium: " << Object.uranium
           << endl;
    //Output powerplants
    for (int i = 0; i < Object.myPowerPlant.size(); ++i) {
        stream << "Powerplant Index " << i + 1 << ": " << endl << Object.myPowerPlant[i] << endl;
    }
    //output hoses
//    for (int i = 0; i < Object.myHouses.size(); ++i) {
//        stream << "House # " << i << " " << Object.myHouses[i] << endl;
//    }
    return stream;
}

int Player::getNumOfPlayers() {
    return numOfPlayers;
}

const string &Player::getMyHouseColor() const {
    return myHouseColor;
}

const string &Player::getPlayerName() const {
    return playerName;
}

int Player::getElektros() const {
    return elektros;
}

int Player::getOil() const {
    return oil;
}

int Player::getCoal() const {
    return coal;
}

int Player::getGarbage() const {
    return garbage;
}

int Player::getUranium() const {
    return uranium;
}

int Player::getNumbHomes() const {
    return numbHomes;
}

int Player::getNumOfCities() const {
    return numOfCities;
}

const vector<Powerplant> &Player::getMyPowerPlant() const {
    return myPowerPlant;
}

void Player::addElektro(int elektro) {
    elektros += elektro;
}

void Player::removeElektro(int elektro) {
    //if the inout value greater than what the player has then output error
    if (elektros - elektro < 0) {
        cout << "Cannot have a negative value for elektro, can only remove " << elektro << " "
                                                                                           "elektro";
        return;
    }
    //otherwise do the removal
    elektros -= elektro;
}

void Player::addOil(int oil) {
    this->oil += oil;
}

void Player::removeOil(int oil) {
    //if the inout value greater than what the player has then output error
    if (this->oil - oil < 0) {
        cout << "Cannot have a negative value for oil, can only remove " << this->oil << " oil";
        return;
    }
    //otherwise do the removal
    this->oil -= oil;
}

void Player::addGarbage(int garbage) {
    this->garbage += garbage;
}

void Player::removeGarabge(int garbage) {
    //if the inout value greater than what the player has then output error

    if (this->garbage - garbage < 0) {
        cout << "Cannot have a negative value for garbage, can only remove " << this->garbage << " garbage";
        return;
    }
    this->garbage -= garbage;
}

void Player::addUranium(int uranium) {
    this->uranium += uranium;
}

void Player::removeUranium(int uranium) {
    if (this->uranium - uranium < 0) {
        cout << "Cannot have a negative value for uranium, can only remove " << this->uranium << " uranium";
        return;
    }
    this->uranium -= uranium;
}

void Player::addCoal(int coal) {
    this->coal += coal;
}

void Player::removeCoal(int coal) {
    if (this->coal - coal < 0) {
        cout << "Cannot have a negative value for coal, can only remove " << this->coal << " coal";
        return;
    }
    this->coal -= coal;
}

void Player::addPowerplant(Powerplant &somePowerplant) {
    //put the powerplant in the array
    myPowerPlant.push_back(somePowerplant);
    //sort the list
    sort(myPowerPlant.begin(), myPowerPlant.end());
}

void Player::removePowerplant(Powerplant &somePowerplant) {
    //remove the powerplant
    std::vector<Powerplant>::iterator position = std::find(myPowerPlant.begin(), myPowerPlant.end(), somePowerplant);
    if (position != myPowerPlant.end()) // == myVector.end() means the element was not found
        myPowerPlant.erase(position);
    //resort the array
    sort(myPowerPlant.begin(), myPowerPlant.end());
}

Powerplant &Player::getPowerPlant(int plantNumber) {
    //ask for a plant number
    cout << "pick a powerplant: ";
    int pos;

    for (int i = 0; i < myPowerPlant.size(); ++i) {
        cout << i << ": " << myPowerPlant[i] << endl;
    }
    cin >> pos;
    //return the number
    Powerplant cpy = Powerplant(myPowerPlant[pos]);
    return cpy;
}

ostream &Player::displayPowerplants(ostream &stream) {
    //show all the oiwerokants
    for (int i = 0; i < myPowerPlant.size(); ++i) {
        stream << myPowerPlant[i] << endl;
    }
    return stream;
}

bool Player::operator<(Player &p1) {
    //if the other player has more conencted cities
    if (this->numOfCities > p1.numOfCities) {
        return false;
    } //if equal number of cities then compare the highest numbered powerplant
    else if (this->numOfCities == p1.numOfCities) {
        return (this->myPowerPlant.front() < p1.myPowerPlant.front());
    }
    return true;
}

bool Player::isAuctionReady() const {
    return auctionReady;
}

void Player::setAuctionReady(bool auctionReady) {
    Player::auctionReady = auctionReady;
    //if the player doesnt want to participate in phase1 then make sure he doesnt participate
    //in the auction rounds either.
    if (!auctionReady) {
        setRoundReady(auctionReady);
    }
}

void Player::setRoundReady(bool roundReady) {
    //if the player tries to join an auction and wanted to skip phase1, then
    //block him from joining the auction
    if (!auctionReady && roundReady) {
        cout << "cannot make the player round ready the player has decided to skip phase 1.";
        return;
    }
    //otherwise set the round
    Player::roundReady = roundReady;
}

bool Player::isRoundReady() const {
    return roundReady;
}

void Player::powerCities() {
    int powerplantChoice;
    int poweredCities = 0;
    int *resourceRef;
    int UsePowerplant;
    char choice;
    do {
        UsePowerplant = 0;
        std::cout << "Do you want to power a plant: ";
        cin >> choice;
        if (tolower(choice) == 'n') {
            std::cout << playerName << " has decided to skip phase 5 \n";
            break;
        }
        std::cout << "Please choose a power plant you want to power: \n";
        for (int i = 0; i < myPowerPlant.size(); i++) {
            if (!canUsePowerplant(myPowerPlant[i])) {
                continue;
            }
            UsePowerplant++;
            cout << i << ": " << myPowerPlant[i] << endl;
        }
        if (UsePowerplant == 0) {
            std::cout << "No powerplants can be powered\n";
            break;
        }
        //take choice
        cin >> powerplantChoice;
        if (myPowerPlant[powerplantChoice].getResourceType() == "Ecological") {
            poweredCities += myPowerPlant[powerplantChoice].getProductionValue();

        } else {
            resourceRef = getResourceRef(myPowerPlant[powerplantChoice].getResourceType());
            *resourceRef -= myPowerPlant[powerplantChoice].getEnergyCost();
            poweredCities += myPowerPlant[powerplantChoice].getProductionValue();
        }
    } while (UsePowerplant);
    if (poweredCities > numOfCities) {
        elektros += PAYMENT[numCities];
        std::cout << playerName << " has powered " << numOfCities << "cities and has a surplus of "
                  << poweredCities - numOfCities
                  << " power" << endl;
        std::cout << PAYMENT[numOfCities] << " elecktros has been given to " << playerName << "\n";
    } else {
        elektros += PAYMENT[poweredCities];
        std::cout << playerName << " has powered " << poweredCities << "cities and has a surplus of 0 " <<
                  " power" << endl;
        std::cout << PAYMENT[poweredCities] << " elecktros has been given to " << playerName << endl;
    }
}

bool Player::canUsePowerplant(const Powerplant &p1) {
    return (p1.getEnergyCost() <= getResource(p1.getResourceType()));
}

int Player::getResource(string resourceVal) {
    transform(resourceVal.begin(), resourceVal.end(), resourceVal.begin(), ::tolower);
    cout << resourceVal << endl;
    if (resourceVal == "coal") {
        return coal;
    } else if (resourceVal == "oil") {
        return oil;
    } else if (resourceVal == "garbage") {
        return garbage;
    } else if (resourceVal == "nuclear") {
        return uranium;
    } else if (resourceVal == "hybrid") {
        return oil;

    } else if (resourceVal == "ecological") {
        return 0;
    } else {
        cout << "Invalid entry returning -1" << endl;
        return -1;
    }
}

int *Player::getResourceRef(string resourceVal) {
    transform(resourceVal.begin(), resourceVal.end(), resourceVal.begin(), ::tolower);
    if (resourceVal == "coal") {
        return &coal;
    } else if (resourceVal == "oil") {
        return &oil;
    } else if (resourceVal == "garbage") {
        return &garbage;
    } else if (resourceVal == "nuclear") {
        return &uranium;
    } else {
        cout << "Invalid entry returning nullptr" << endl;
        return nullptr;
    }
}

//Buy resources method - Call this method in the driver, using a loop for each player
void Player::buyResources(ResourceMarket *resourceMarket) {
    //Declare variables
    string userInput;
    int playerSelection;
    int playerOilCapacity, playerCoalCapacity, playerUraniumCapacity, playerGarbageCapacity;
    bool validInput = false;
    bool playerTurn = true;
    while (playerTurn) {
        validInput = false;
        std::cout << "\nIt is currently " << playerName << "'s turn to buy resources" << std::endl;
        resourceMarket->printResourceMarketStock();
        std::cout << "Enter 1 to buy a unit of oil" << std::endl;
        std::cout << "Enter 2 to buy a unit of coal" << std::endl;
        std::cout << "Enter 3 to buy a unit of uranium" << std::endl;
        std::cout << "Enter 4 to buy a unit of garbage" << std::endl;
        std::cout << "Enter 5 to stop buying resources" << std::endl;
        //get INPUT
        cin >> userInput;
        //cout<<"The user input is "<<userInput<<std::endl;
        //VALIDATE INPUT
        while (!validInput) {
            if (!(userInput.size() == 1)) {
                //validInput == false;
                std::cout << "INVALID INPUT - THERE SHOULD ONLY BE 1 CHARACTER ENTERED" << std::endl;
            }//if
            else {
                if (isdigit(userInput.at(0))) {
                    //cout<<"debug 2 - input at(0) isdigit\n";
                    playerSelection = std::stoi(userInput);
                    if (playerSelection > 0 && playerSelection < 6) {
                        validInput = true;
                        //std::cout<<"THE USER INPUT IS VALID\n";
                    }//close inner if between 0 and 6
                }//close if is 1 digit
            }//1 character entered by the user
            //std::cout<<"EXITING VALIDATION LOOP\n";
        }//close while not valid input
        if (playerSelection == 1) {//player selects to buy 1 oil
            //Validate that the 1)player has enough money	2)space to purchase the resource	3)There is oil available to purchase
            if (this->elektros >= resourceMarket->getOilPrice() && this->getOilCap() >= 1 &&
                resourceMarket->getOil() > 0) {
                //Add oil to player
                this->addOil(1);
                //Charge player elektros for the resource purchase
                this->elektros -= resourceMarket->getOilPrice();
                //Remove oil from supply
                resourceMarket->removeOil();
            }//close if player is able to purchase the oil
            else if (this->elektros < resourceMarket->getOilPrice())
                std::cout << "Sorry, you do not have enough elektros to purchase this unit of oil\nYou currently have "
                          << elektros << " elektros, and require at least " << resourceMarket->getOilPrice()
                          << " elektros\n";
            else if (this->getOilCap() < 1)
                std::cout
                        << "Sorry, you do not have enough room in your power plants to store more oil\nYou currently have "
                        << oil << " oil\n";
            else if (resourceMarket->getOil() == 0)
                std::cout << "Sorry, there is no oil left on the market to be purchased\n";
        }//close if player selects option 1 to buy 1 oil
        else if (playerSelection == 2) {//player selects to buy 2 coal
            //Validate that the 1)player has enough money	2)space to purchase the resource	3)There is oil available to purchase
            if (this->elektros >= resourceMarket->getCoalPrice() && this->getCoalCap() >= 1 &&
                resourceMarket->getCoal() > 0) {
                //Add oil to player
                this->addCoal(1);
                //Charge player elektros for the resource purchase
                this->elektros -= resourceMarket->getCoalPrice();
                //Remove oil from supply
                resourceMarket->removeCoal();
            }//close if player is able to purchase the oil
            else if (this->elektros < resourceMarket->getCoalPrice())
                std::cout << "Sorry, you do not have enough elektros to purchase this unit of coal\nYou currently have "
                          << elektros << " elektros, and require at least " << resourceMarket->getCoalPrice()
                          << " elektros\n";
            else if (this->getCoalCap() < 1)
                std::cout
                        << "Sorry, you do not have enough room in your power plants to store more coal\nYou currently have "
                        << coal << " coal\n";
            else if (resourceMarket->getCoal() == 0)
                std::cout << "Sorry, there is no coal left on the market to be purchased\n";
        }//close if player selects option 2 to buy 1 coal
        else if (playerSelection == 3) {//player selects to buy 3 uranium
            //Validate that the 1)player has enough money	2)space to purchase the resource	3)There is uranium available to purchase
            if (this->elektros >= resourceMarket->getUraniumPrice() && this->getUraniumCap() >= 1 &&
                resourceMarket->getUranium() > 0) {
                //Add oil to player
                this->addUranium(1);
                //Charge player elektros for the resource purchase
                this->elektros -= resourceMarket->getUraniumPrice();
                //Remove uranium from supply
                resourceMarket->removeUranium();
            }//close if player is able to purchase the uranium
            else if (this->elektros < resourceMarket->getUraniumPrice())
                std::cout
                        << "Sorry, you do not have enough elektros to purchase this unit of uranium\nYou currently have "
                        << elektros << " elektros, and require at least " << resourceMarket->getUraniumPrice()
                        << " elektros\n";
            else if (this->getUraniumCap() < 1)
                std::cout
                        << "Sorry, you do not have enough room in your power plants to store more uranium\nYou currently have "
                        << uranium << " uranium\n";
            else if (resourceMarket->getUranium() == 0)
                std::cout << "Sorry, there is no uranium left on the market to be purchased\n";
        }//close if player selects option 3 to buy 1 uranium
        else if (playerSelection == 4) {//player selects to buy 4 garbage
            //Validate that the 1)player has enough money	2)space to purchase the resource	3)There is uranium available to purchase
            if (this->elektros >= resourceMarket->getGarbagePrice() && this->getGarbageCap() >= 1 &&
                resourceMarket->getGarbage() > 0) {
                //Add oil to player
                this->addGarbage(1);
                //Charge player elektros for the resource purchase
                this->elektros -= resourceMarket->getGarbagePrice();
                //Remove uranium from supply
                resourceMarket->removeGarbage();
            }//close if player is able to purchase the uranium
            else if (this->elektros < resourceMarket->getGarbagePrice())
                std::cout
                        << "Sorry, you do not have enough elektros to purchase this unit of garbage\nYou currently have "
                        << elektros << " elektros, and require at least " << resourceMarket->getGarbagePrice()
                        << " elektros\n";
            else if (this->getUraniumCap() < 1)
                std::cout
                        << "Sorry, you do not have enough room in your power plants to store more garbage\nYou currently have "
                        << garbage << " garbage\n";
            else if (resourceMarket->getUranium() == 0)
                std::cout << "Sorry, there is no garbage left on the market to be purchased\n";
        }//close if player selects option 4 to buy 1 garbage
        else if (playerSelection == 5) {//player selects 5 to stop buying rersources
            playerTurn = false;
        }//close else if player selects 5 to end buying resources
    }//close while player turn
}//close buy resources

//Get values for amount of resources that can be stored based on number of power plants and their limits
int Player::getOilCap() {
    int returnValue = 0;
    for (int i = 0; i < myPowerPlant.size(); i++) {
        //check if plant is of
        if (getPowerPlant(i).getResourceType() == "Oil" || getPowerPlant(i).getResourceType() == "Hybrid")
            returnValue += 2 * (getPowerPlant(i).getEnergyCost());
    }//close for loop for each powerplant that the player owns
    return (returnValue - this->oil);
}//close get oil cap function
int Player::getCoalCap() {
    int returnValue = 0;
    for (int i = 0; i < myPowerPlant.size(); i++) {
        //check if plant is of
        if (getPowerPlant(i).getResourceType() == "Coal" || getPowerPlant(i).getResourceType() == "Hybrid")
            returnValue += 2 * (getPowerPlant(i).getEnergyCost());
    }//close for loop for each powerplant that the player owns
    return (returnValue - this->coal);
}//close get coal cap function
int Player::getUraniumCap() {
    int returnValue = 0;
    for (int i = 0; i < myPowerPlant.size(); i++) {
        //check if plant is of
        if (getPowerPlant(i).getResourceType() == "Uranium")
            returnValue += 2 * (getPowerPlant(i).getEnergyCost());
    }//close for loop for each powerplant that the player owns
    return (returnValue - this->uranium);
}//close get Uranium cap function
int Player::getGarbageCap() {
    int returnValue = 0;
    for (int i = 0; i < myPowerPlant.size(); i++) {
        //check if plant is of
        if (getPowerPlant(i).getResourceType() == "Garbage")
            returnValue += 2 * (getPowerPlant(i).getEnergyCost());
    }//close for loop for each powerplant that the player owns
    return (returnValue - this->garbage);
}//close get oil garbage function

//Building cities
//Function to be called in driver, in a loop by each team player
//Will use the shortest path algorithm defined in Map.cpp to return the distance between 2 vertices
//ADD BOOLEAN TO PLAYER CLASS TO FLAG WHETHER THE FIRST CITY HAS BEEN CHOSEN
void Player::buyCities(Map *map, int gamePhaseNumber) {
    //DECLARE VARIABLES
    int connectionCost = 0;
    int houseCost = 10;
    int totalHouseBuildingCost;
    std::string userIn;
    Vertex houseBuildingLocation;
    bool validEntry = false;
    bool playerTurn = true;
    bool houseAvailableAtLocation = false;
    bool foundVertex = false;
    vector<std::string> nameOfPlayerCities;
    vector<std::string> nameOfMapCities;
    vector<Vertex> existingCities = map->getVertices();

    //START LOOP FOR THE PLAYER BUILDING PHASE
    while (playerTurn) {
        //Update booleans for iteration
        validEntry = false;
        houseAvailableAtLocation = false;
        std::cout << "STARTING playerTurn LOOP for " << playerName << "\n";
        //START LOOP FOR VALID INPUT
        while (!validEntry) {
            //DISPLAY MAP AND AVAILABLE CITIES
            cout << "Now displaying map\n" << *map << "\n";
            if (!startedNetwork)
                cout << playerName << " your network is currently empty\nYou can start your city anywhere available\n";
            else {
                //Display player network
                std::cout << "Now displaying " << playerName << "'s network:\n";
                for (int i = 0; i < myHouses.size(); i++)
                    std::cout << "House #" << i << " located at: " << myHouses.at(i) << "\n";
            }//close else, player already started network

            //PROMPT PLAYER TO SELECT CITY
            std::cout << playerName
                      << ", please enter the name of the city that you would like to add to your network, or type PASS to continue\n";
            std::cin >> userIn;
            if (userIn == "PASS") {
                cout << "\n" << playerName << " has selected to pass\n";
                playerTurn = false;        //exits outer while loop
                validEntry = true;        //exits inner while loop
                return;
            }//close if player selects PASS
            else {
                std::cout << "Debug 1 - entered else, not PASS\n";
                //ENTER VALIDATE AND RE-SELECT
                //VALIDATE SELECTION	--> Validate that the vertex exists, if new network, validate that its not owned
                //Validation 1 - Existence of vertex with that name
                for (int i = 0; i < existingCities.size(); i++)
                    if (existingCities.at(i).getName() == userIn) {
                        validEntry = true;
                        std::cout
                                << "\nThe vertex entered has passed the 1st verification test, because it exists on the map\n";
                    }//close if valid entry found
                if (!validEntry)
                    std::cout << "\nThe vertex entered is invalid, because it does not exist on the map\n";

                //Validation 2 - player does not own that city and it is available
                if (validEntry && startedNetwork) {
                    //Make invalid if a match is already found
                    for (int i = 0; i < myHouses.size(); i++)
                        if (myHouses.at(i) == userIn) {
                            validEntry = false;
                            std::cout << "\nError - " << playerName << " already owns the vertex " << userIn << "\n";
                        }//close if found player owns a house at this vertex/city
                }//close if vertex exists and network has been started

            }//close else player selects a City(Vertex)
        }//close while invalidEntry loop

        //CALCULATE CONNECTION COST --> CHECK IF FIRST CITY HAS BEEN SELECTED, IF NO, CONNECTION COST = 0
        if (!startedNetwork)
            connectionCost = 0;
        else {
            std::vector<int> shortestPathToAllVertices;
            for (int i = 0; i < myHouses.size(); i++)
                //Get the shortest path from the user selected city to all other cities in the network
                shortestPathToAllVertices.push_back(map->shortestPath(userIn, myHouses.at(i)));
            std::sort(shortestPathToAllVertices.begin(), shortestPathToAllVertices.end());
            connectionCost = shortestPathToAllVertices.at(0);
        }//else get the shortest path between the vertex given and
        std::cout << "The connection cost to his city is: " << connectionCost << std::endl;

        //GET HOUSE COST AND ADD TO TOTAL
        int totalCost = (connectionCost + map->findVertex(userIn).getCost());
        std::cout << "The total cost to build a house at this city is: " << totalCost << std::endl;
        std::cout << playerName << " has " << elektros << std::endl;

        //VALIDATE THAT NO OTHER PLAYER IS ALREADY AT THIS LOCATION
        //Vertex v = map->findVertex(userIn);
        houseAvailableAtLocation = map->canBuildHouse(map->findVertex(userIn), gamePhaseNumber);
        cout << "\nHouse available at this location? " << houseAvailableAtLocation << "\n";

        //VALIDATE THAT PLAYER HAS ENOUGH ELEKTROS
        if (totalCost > elektros) {
            std::cout << playerName << " does not have enough elektros to purchase a house at the location: " << userIn
                      << "\n";
            std::cout << playerName << " has " << elektros << " the total cost to build at location: " << userIn
                      << " is " << totalCost;
        }//if player does not have enough elektros

        if (!houseAvailableAtLocation)
            std::cout << "\nCan not Build at this location, there is already a house here\n";

        if (totalCost <= elektros && houseAvailableAtLocation) {
            std::cout << playerName << " has built a house in " << userIn << "\n";
            //UPDATE ALL OBJECTS - VERTEX, NUMOFCITIES, Player.numOfCities, Player.myHouses, HOUSE OBJECT?
            std::cout << "Debug A\n";
            elektros -= totalCost;
            std::cout << "Debug B\n";
            std::cout << "B1 - Display vertex below - map->findVertex( userIn ).getName(): \n";
            std::cout << map->findVertex(userIn).getName() << std::endl;
            string nameOfNewHouseLocation = map->findVertex(userIn).getName();
            std::cout << "B2.... \n";
            std::cout << nameOfNewHouseLocation << "\n";
            std::cout << "B3.... \n";
            myHouses.push_back(nameOfNewHouseLocation);    // <--- Program exits here
            std::cout << "Debug C\n";
            numOfCities++;
            std::cout << "Debug D\n";
            map->findVertexP(userIn)->setPlayer(playerName);
            std::cout << "Debug E\n";
            startedNetwork = true;
            std::cout << "Debug F\n";
        }//close else, player has added this city to his network
        std::cout << "Debug Finish while playerTurn iteration\n";
    }//close while player turn
    cout << "End of " << playerName << "'s turn to build houses\n";
}

void Player::setNumOfCities(int numOfCities) {
    Player::numOfCities = numOfCities;
}


//close build cities
