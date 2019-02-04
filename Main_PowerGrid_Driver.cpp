/*
 * Main_PowerGrid_Driver.cpp
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 445
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


//Include classes in other files
#include "Player.h"
#include "Card.h"
#include "City.h"

//Name Space
using namespace Mike;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

	//Declare variables
	int numOfPlayers;
	Player player1;
	//Player * p1Ptr = new player1();
	//Player players[];
	//string pNames[];

	//Welcome Message
	cout << "Hello and welcome to POWER GRID V1.0\n\n" ;

	//Prompt users for number of players
	numOfPlayers = player1.promptForNumOfPlayers();

	cout << "The number of players are: " << numOfPlayers << endl << endl ;

	//Create players
	//player1.promptPlayerForName();


	Player players[numOfPlayers];
	//Enter player information
	for (int i = 0 ; i < numOfPlayers ; i++)
		players[i].promptPlayerForName();

	//Print details for each player
	for (int i = 0 ; i < numOfPlayers ; i++){
		cout << endl << players[i].toString() << endl ;
		cout << "Iteration " << i << " of the printing players loop" << endl;
	}//close for


	//GARBAGE COLLECTION
	delete players;
/*
	for (int i = 0 ; i < numOfPlayers ; i++)
		delete players[i];
		//players[i].~Player();
*/





	//exit call and pause
	string anykey;
	cout << "Press any key to continue";
	cin >> anykey;
	return 0;
}// close main loop
