
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
#include "../../Powerplant/Resource/Resource.h"
#include <string>
#include <iostream>

int Player::numOfPlayers=0;
vector<string> Player::houseColor = {"Green","Blue","Black","Pink","Yellow","Orange"};

//ADD THIS ATTRIBUTE TO PLAYER CLASS FOR FLAGGING WETHER NETWORK OF CITIES HAS BEEN STARTED
bool startedNetwork = false;
std::vector<string> myHouses;

//Constructors
/**
 * Player default constructor takes the playername the choice of house color and sets variables to default
 * values at start of the game
 */
Player::Player() {
	cout << "Welcome Player " << numOfPlayers+1 << "!" << endl;
	if (numOfPlayers == MAXNUMBERPLAYERS) {
		std::cout << "Max Number of players reached, cannot create more";
		return;
	}
	cout << "Please enter your player name: " << endl;
	cin >> playerName;

	cout << "Please select a number for a house color:" << endl;
	for (int i = 0; i < houseColor.size() ; ++i) {
		cout << i << ":" << houseColor[i] << endl;
	}
	int choice;
	cin >> choice;
	myHouseColor = houseColor[choice];
	houseColor.erase(houseColor.begin()+choice);

	startedNetwork = false;
	elektros = DEFAULTELECTRO;
	oil = DEFAULTRESOURCE;
	coal = DEFAULTRESOURCE;
	uranium = DEFAULTRESOURCE;
	garbage = DEFAULTRESOURCE;
	numOfCities = DEFAULTHOME;
	numbHomes = DEFAULTHOME;
	numOfPlayers++;
}//close constructor

/**
 *
 * @param nameIn parametrized constructor takes name
 */
Player::Player(std::string nameIn) {
	if (numOfPlayers == MAXNUMBERPLAYERS) {
		std::cout << "Max Number of players reached, cannot create more";
		return;
	}
	playerName = nameIn;
	startedNetwork = false;
	this->myHouseColor = myHouseColor;
	elektros = DEFAULTELECTRO;
	oil = DEFAULTRESOURCE;
	coal = DEFAULTRESOURCE;
	uranium = DEFAULTRESOURCE;
	numOfCities = DEFAULTHOME;
	numbHomes = DEFAULTHOME;
	this->numOfPlayers++;
}

Player::~Player() {
	std::cout << "Player " << playerName << " has left the game" << endl;
}//close destructor

//Setters and Getters


////Other methods
////Prompt user number of players
//    int Player::promptForNumOfPlayers() {
//        int numOfPlayers = 0;
//        //Loop until numOfPlayers is a valid number
//        while (numOfPlayers < 2 || numOfPlayers > 6) {
//            std::cout
//                    << "Please enter the number of players that will be playing Power Grid?\n(Enter a number from 2 to 6 and press ENTER\n\n";
//
//            // *****ERROR HANDLE FOR NON INTEGER TYPE INPUT
//            std::cin >> numOfPlayers;
//
//            //validate user input
//            if (numOfPlayers < 2 || numOfPlayers > 6)
//                std::cout
//                        << "THE NUMBER THAT YOU ENTERED IS INVALID\n only 2, 3, 4, 5 or players can play Power Grid\n\n";
//        }//close while looking for valid number of players input
//        return numOfPlayers;
//    }//close function prompt user

////Prompt user to input name
//    void Player::promptPlayerForName() {
//        std::string pName = "THISstringShouldGETchanged";
//        std::cout << "\nPlease enter the players name\n";
//        std::cin >> pName;
//        playerName = pName;
//    }//close function prompt user



ostream& Player::displayHouses(ostream& stream) {
	for (int i = 0; i < myHouses.size(); ++i) {
		stream << myHouses.at(i) << endl;
	}
	return stream;
}


ostream &operator<<(ostream &stream, Player &Object) {
	stream << "Player Name: " << Object.playerName << "\n" << "# Electros: " << Object.elektros << "\n"
			<< "Total # Resources: " << Object.oil + Object.coal + Object.garbage + Object.uranium << "\n" << "# Oil: " << Object.oil << "\n"
			<< "Coal: " << Object.coal << "\n" << "Garbage: " << Object.garbage << "\n" << "Uranium: " << Object.uranium << endl;
	for (int i = 0; i < Object.myPowerPlant.size(); ++i) {
		stream << "Powerplant #:" << i+1 << ": " << Object.myPowerPlant[i] << endl;
	}
	for (int i = 0; i < Object.myHouses.size(); ++i) {
		stream << "House # " << i <<  " " <<  Object.myHouses.at(i) << endl;
	}
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
/*
int Player::getOil() const {
	return this->oil;
}
*/
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
	if (elektros - elektro < 0) {
		cout << "Cannot have a negative value for elektro, can only remove " << elektro << " "
				"elektro";
		return;
	}
	elektros -= elektro;
}

void Player::addOil(int oil) {
	this->oil += oil;
}

void Player::removeOil(int oil) {
	if (this->oil - oil < 0) {
		cout << "Cannot have a negative value for oil, can only remove " << this->oil << " oil";
		return;
	}
	this->oil -= oil;
}

void Player::addGarbage(int garbage) {
	this->garbage += garbage;
}

void Player::removeGarabge(int garbage) {
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
		cout << "Cannot have a negative value for coal, can only remove " << this->coal<< " coal";
		return;
	}
	this->coal -= coal;
}



void Player::addPowerplant(Powerplant& somePowerplant) {
	myPowerPlant.push_back(somePowerplant);
}

void Player::removePowerplant(Powerplant& somePowerplant) {
	std::vector<Powerplant>::iterator position = std::find(myPowerPlant.begin(), myPowerPlant.end(),somePowerplant);
	if (position != myPowerPlant.end()) // == myVector.end() means the element was not found
		myPowerPlant.erase(position);
}
Powerplant& Player::getPowerPlant(int plantNumber) {
	cout << "pick a powerplant: ";
	int pos;
	for (int i = 0; i < myPowerPlant.size(); ++i) {
		cout << i << ": " << myPowerPlant[i] << endl;
	}
	cin>>pos;
	Powerplant cpy = Powerplant(myPowerPlant[pos]) ;
	return cpy;
}

ostream& Player::displayPowerplants(ostream& stream) {
	for (int i = 0; i < myPowerPlant.size(); ++i) {
		stream << myPowerPlant[i] << endl;
	}
	return  stream;
}

//void Player::addHouses(Houses& someHouse) {
//	myHouses.push_back(someHouse);
//	numbHomes++;
//	numOfCities++;
//}
//
//void Player::removeHouses(Houses& someHouse) {
//	std::vector<Houses>::iterator position = std::find(myHouses.begin(), myHouses.end(),someHouse);
//	if (position != myHouses.end()) { // == myVector.end() means the element was not found
//		myHouses.erase(position);
//	}
//	numbHomes--;
//	numOfCities--;
//}

//Buy resources method - Call this method in the driver, using a loop for each player
void Player::buyResources(ResourceMarket *resourceMarket){
	//Declare variables
	string userInput;
	int playerSelection;
	int playerOilCapacity, playerCoalCapacity, playerUraniumCapacity, playerGarbageCapacity;
	bool validInput = false;
	bool playerTurn = true;
	while (playerTurn){
		validInput = false;
		std::cout<<"\nIt is currently "<<playerName<<"'s turn to buy resources"<<std::endl;
		resourceMarket->printResourceMarketStock();
		std::cout<<"Enter 1 to buy a unit of oil"<<std::endl;
		std::cout<<"Enter 2 to buy a unit of coal"<<std::endl;
		std::cout<<"Enter 3 to buy a unit of uranium"<<std::endl;
		std::cout<<"Enter 4 to buy a unit of garbage"<<std::endl;
		std::cout<<"Enter 5 to stop buying resources"<<std::endl;
		//get INPUT
		cin >> userInput;
		//cout<<"The user input is "<<userInput<<std::endl;
		//VALIDATE INPUT
		while ( !validInput ){
			if (!(userInput.size()==1)){
				//validInput == false;
				std::cout<<"INVALID INPUT - THERE SHOULD ONLY BE 1 CHARACTER ENTERED"<<std::endl;
			}//if
			else{
				cout<<"debug 1 - input is valid\n";

				if (isdigit(userInput.at(0))) {
					cout<<"debug 2 - input at(0) isdigit\n";
					playerSelection = std::stoi( userInput );
					if ( playerSelection > 0 && playerSelection < 6) {
						validInput = true;
						//std::cout<<"THE USER INPUT IS VALID\n";
					}//close inner if between 0 and 6
				}//close if is 1 digit
			}//1 character entered by the user
			//std::cout<<"EXITING VALIDATION LOOP\n";
		}//close while not valid input
		if (playerSelection == 1){//player selects to buy 1 oil
			//Validate that the 1)player has enough money	2)space to purchase the resource	3)There is oil available to purchase
			if ( this->elektros >= resourceMarket->getOilPrice() && this->getOilCap() >= 1 && resourceMarket->getOil() > 0){
				//Add oil to player
				this->addOil(1);
				//Charge player elektros for the resource purchase
				this->elektros -= resourceMarket->getOilPrice();
				//Remove oil from supply
				resourceMarket->removeOil();
			}//close if player is able to purchase the oil
			else if ( this->elektros < resourceMarket->getOilPrice() )
				std::cout<<"Sorry, you do not have enough elektros to purchase this unit of oil\nYou currently have "<<elektros<<" elektros, and require at least "<<resourceMarket->getOilPrice()<<" elektros\n";
			else if ( this->getOilCap() < 1 )
				std::cout<<"Sorry, you do not have enough room in your power plants to store more oil\nYou currently have "<<oil<<" oil\n";
			else if ( resourceMarket->getOil() == 0 )
				std::cout<<"Sorry, there is no oil left on the market to be purchased\n";
		}//close if player selects option 1 to buy 1 oil
		else if (playerSelection == 2){//player selects to buy 2 coal
			//Validate that the 1)player has enough money	2)space to purchase the resource	3)There is oil available to purchase
			if ( this->elektros >= resourceMarket->getCoalPrice() && this->getCoalCap() >= 1 && resourceMarket->getCoal() > 0){
				//Add oil to player
				this->addCoal(1);
				//Charge player elektros for the resource purchase
				this->elektros -= resourceMarket->getCoalPrice();
				//Remove oil from supply
				resourceMarket->removeCoal();
			}//close if player is able to purchase the oil
			else if ( this->elektros < resourceMarket->getCoalPrice() )
				std::cout<<"Sorry, you do not have enough elektros to purchase this unit of coal\nYou currently have "<<elektros<<" elektros, and require at least "<<resourceMarket->getCoalPrice()<<" elektros\n";
			else if ( this->getCoalCap() < 1 )
				std::cout<<"Sorry, you do not have enough room in your power plants to store more coal\nYou currently have "<<coal<<" coal\n";
			else if ( resourceMarket->getCoal() == 0 )
				std::cout<<"Sorry, there is no coal left on the market to be purchased\n";
		}//close if player selects option 2 to buy 1 coal
		else if (playerSelection == 3){//player selects to buy 3 uranium
			//Validate that the 1)player has enough money	2)space to purchase the resource	3)There is uranium available to purchase
			if ( this->elektros >= resourceMarket->getUraniumPrice() && this->getUraniumCap() >= 1 && resourceMarket->getUranium() > 0){
				//Add oil to player
				this->addUranium(1);
				//Charge player elektros for the resource purchase
				this->elektros -= resourceMarket->getUraniumPrice();
				//Remove uranium from supply
				resourceMarket->removeUranium();
			}//close if player is able to purchase the uranium
			else if ( this->elektros < resourceMarket->getUraniumPrice() )
				std::cout<<"Sorry, you do not have enough elektros to purchase this unit of uranium\nYou currently have "<<elektros<<" elektros, and require at least "<<resourceMarket->getUraniumPrice()<<" elektros\n";
			else if ( this->getUraniumCap() < 1 )
				std::cout<<"Sorry, you do not have enough room in your power plants to store more uranium\nYou currently have "<<uranium<<" uranium\n";
			else if ( resourceMarket->getUranium() == 0 )
				std::cout<<"Sorry, there is no uranium left on the market to be purchased\n";
		}//close if player selects option 3 to buy 1 uranium
		else if (playerSelection == 4){//player selects to buy 4 garbage
			//Validate that the 1)player has enough money	2)space to purchase the resource	3)There is uranium available to purchase
			if ( this->elektros >= resourceMarket->getGarbagePrice() && this->getGarbageCap() >= 1 && resourceMarket->getGarbage() > 0){
				//Add oil to player
				this->addGarbage(1);
				//Charge player elektros for the resource purchase
				this->elektros -= resourceMarket->getGarbagePrice();
				//Remove uranium from supply
				resourceMarket->removeGarbage();
			}//close if player is able to purchase the uranium
			else if ( this->elektros < resourceMarket->getGarbagePrice() )
				std::cout<<"Sorry, you do not have enough elektros to purchase this unit of garbage\nYou currently have "<<elektros<<" elektros, and require at least "<<resourceMarket->getGarbagePrice()<<" elektros\n";
			else if ( this->getUraniumCap() < 1 )
				std::cout<<"Sorry, you do not have enough room in your power plants to store more garbage\nYou currently have "<<garbage<<" garbage\n";
			else if ( resourceMarket->getUranium() == 0 )
				std::cout<<"Sorry, there is no garbage left on the market to be purchased\n";
		}//close if player selects option 4 to buy 1 garbage
		else if (playerSelection == 5){//player selects 5 to stop buying rersources
			playerTurn = false;
		}//close else if player selects 5 to end buying resources
	}//close while player turn
}//close buy resources

//Get values for amount of resources that can be stored based on number of power plants and their limits
int Player::getOilCap(){
	int returnValue = 0;
	for (int i = 0 ; i < myPowerPlant.size() ; i++ ){
		//check if plant is of
		if ( getPowerPlant(i).getResourceType() == "Oil" || getPowerPlant(i).getResourceType() == "Hybrid" )
			returnValue += 2*(getPowerPlant(i).getEnergyCost());
	}//close for loop for each powerplant that the player owns
	return (returnValue - this->oil);
}//close get oil cap function
int Player::getCoalCap(){
	int returnValue = 0;
	for (int i = 0 ; i < myPowerPlant.size() ; i++ ){
		//check if plant is of
		if ( getPowerPlant(i).getResourceType() == "Coal" || getPowerPlant(i).getResourceType() == "Hybrid" )
			returnValue += 2*(getPowerPlant(i).getEnergyCost());
	}//close for loop for each powerplant that the player owns
	return (returnValue - this->coal);
}//close get coal cap function
int Player::Player::getUraniumCap(){
	int returnValue = 0;
	for (int i = 0 ; i < myPowerPlant.size() ; i++ ){
		//check if plant is of
		if ( getPowerPlant(i).getResourceType() == "Uranium" )
			returnValue += 2*(getPowerPlant(i).getEnergyCost());
	}//close for loop for each powerplant that the player owns
	return (returnValue - this->uranium);
}//close get Uranium cap function
int Player::getGarbageCap(){
	int returnValue = 0;
	for (int i = 0 ; i < myPowerPlant.size() ; i++ ){
		//check if plant is of
		if ( getPowerPlant(i).getResourceType() == "Garbage" )
			returnValue += 2*(getPowerPlant(i).getEnergyCost());
	}//close for loop for each powerplant that the player owns
	return (returnValue - this->garbage);
}//close get oil garbage function

//Building cities
//Function to be called in driver, in a loop by each team player
//Will use the shortest path algorithm defined in Map.cpp to return the distance between 2 vertices
//ADD BOOLEAN TO PLAYER CLASS TO FLAG WHETHER THE FIRST CITY HAS BEEN CHOSEN
void Player::buyCities(Map *map, int gamePhaseNumber){
	//DECLARE VARIABLES
	int connectionCost = 0;
	int houseCost = 10;
	int totalHouseBuildingCost;
	std::string userIn;
	Vertex houseBuildingLocation;
	bool validEntry = false;
	bool playerTurn = true;
	bool houseAvailbleAtLocation = false;
	bool foundVertex = false;
	vector<std::string> nameOfPlayerCities;
	vector<std::string> nameOfMapCities;
	vector<Vertex> existingCities = map->getVertices();

	//START LOOP FOR THE PLAYER BUILDING PHASE
	while (playerTurn){
		//Update booleans for iteration
		validEntry = false;
		houseAvailbleAtLocation = false;
		std::cout<<"STARTING playerTurn LOOP for "<<playerName<<"\n";
		//START LOOP FOR VALID INPUT
		while (!validEntry){
			//DISPLAY MAP AND AVAILABLE CITIES
			cout<<"Now displaying map\n"<<*map<<"\n";
			if (!startedNetwork)
				cout<<playerName<<" your network is currently empty\nYou can start your city anywhere available\n";
			else {
				//Display player network
				std::cout<<"Now displaying "<<playerName<<"'s network:\n";
				for (int i = 0 ; i < myHouses.size() ; i++)
					std::cout<<"House #"<<i<<" located at: "<<myHouses.at(i)<<"\n";
			}//close else, player already started network

			//PROMPT PLAYER TO SELECT CITY
			std::cout<<playerName<<", please enter the name of the city that you would like to add to your network, or type PASS to continue\n";
			std::cin>>userIn;
			if (userIn == "PASS") {
				cout << "\n"<<playerName<<" has selected to pass\n";
				playerTurn = false;		//exits outer while loop
				validEntry = true;		//exits inner while loop
				return;
			}//close if player selects PASS
			else{
				std::cout<<"Debug 1 - entered else, not PASS\n";
				//ENTER VALIDATE AND RE-SELECT
				//VALIDATE SELECTION	--> Validate that the vertex exists, if new network, validate that its not owned
				//Validation 1 - Existence of vertex with that name
				for (int i = 0 ; i < existingCities.size() ; i++ )
					if ( existingCities.at(i).getName() == userIn) {
						validEntry = true;
						std::cout<<"\nThe vertex entered has passed the 1st verification test, because it exists on the map\n";
					}//close if valid entry found
				if (!validEntry)
					std::cout<<"\nThe vertex entered is invalid, because it does not exist on the map\n";

				//Validation 2 - player does not own that city and it is available
				if (validEntry && startedNetwork){
					//Make invalid if a match is already found
					for (int i = 0 ; i < myHouses.size() ; i++)
						if (myHouses.at(i) == userIn){
							validEntry = false;
							std::cout<<"\nError - "<<playerName<<" already owns the vertex "<<userIn<<"\n";
						}//close if found player owns a house at this vertex/city
				}//close if vertex exists and network has been started

			}//close else player selects a City(Vertex)
		}//close while invalidEntry loop

		//CALCULATE CONNECTION COST --> CHECK IF FIRST CITY HAS BEEN SELECTED, IF NO, CONNECTION COST = 0
		if (!startedNetwork)
			connectionCost = 0;
		else{
			std::vector<int> shortestPathToAllVertices;
			for (int i = 0 ; i < myHouses.size() ; i++)
				//Get the shortest path from the user selected city to all other cities in the network
				shortestPathToAllVertices.push_back(  map->shortestPath(userIn, myHouses.at(i)) );
			std::sort( shortestPathToAllVertices.begin(), shortestPathToAllVertices.end() );
			connectionCost = shortestPathToAllVertices.at(0);
		}//else get the shortest path between the vertex given and
		std::cout<<"The connection cost to this city is: "<<connectionCost<<std::endl;

		//GET HOUSE COST AND ADD TO TOTAL
		int totalCost = ( connectionCost + map->findVertex(userIn).getCost() );
		std::cout<<"The total cost to build a house at this city is: "<<totalCost<<std::endl;
		std::cout<<playerName<<" has "<<elektros<<std::endl;

		//VALIDATE THAT NO OTHER PLAYER IS ALREADY AT THIS LOCATION
		//houseAvailbleAtLocation = map->canBuildHouse(  map->findVertex(userIn), gamePhaseNumber); <--------- just fix the error caused here
		//Vertex v = map->findVertex(userIn);
		//houseAvailbleAtLocation = map->canBuildHouse( map->findVertex(userIn), gamePhaseNumber);
		//VALIDATE THAT PLAYER HAS ENOUGH ELEKTROS
		if ( totalCost > elektros ){
			std::cout<< playerName <<" does not have enough elektros to purchase a house at the location: "<<userIn<<"\n";
			std::cout<<playerName<<" has "<<elektros<<" the total cost to build at location: "<<userIn<<" is "<<totalCost;
		}//if player does not have enough elektros

		else if ( !houseAvailbleAtLocation )
			std::cout<<"\nCan not Build at this location, there is already a house here\n";
		else{
			std::cout<<playerName<<" has built a house in "<<userIn<<"\n";
		//UPDATE ALL OBJECTS - VERTEX, NUMOFCITIES, Player.numOfCities, Player.myHouses, HOUSE OBJECT?
			std::cout<<"Debug A\n";
			elektros -= totalCost;
			std::cout<<"Debug B\n";
			std::cout<<"B1 - Display vertex below - map->findVertex( userIn ).getName(): \n";
			std::cout<<map->findVertex( userIn ).getName()<<std::endl;
			string nameOfNewHouseLocation = map->findVertex( userIn ).getName();
			std::cout<<"B2.... \n";
			std::cout<<nameOfNewHouseLocation<<"\n";
			std::cout<<"B3.... \n";
			myHouses.push_back( nameOfNewHouseLocation );	// <--- Program exits here
			std::cout<<"Debug C\n";
			numOfCities++;
			std::cout<<"Debug D\n";
			map->findVertex( userIn ).setPlayer( playerName );
			std::cout<<"Debug E\n";
			startedNetwork = true;
		}//close else, player has added this city to his network
		std::cout<<"Debug Finish while playerTurn iteration\n";
	}//close while player turn
	cout<<"End of "<<playerName<<"'s turn to build houses\n";
}//close build cities
