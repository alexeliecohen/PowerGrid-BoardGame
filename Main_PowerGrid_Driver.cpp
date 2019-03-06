
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

#include "Map/Map.h"

//Include classes in other files
#include "Powerplant/Player.h"
//#include "Card.h"
#include "Powerplant/City.h"

//Name Space
using namespace Mike;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

//	//Declare variables
//	int numOfPlayers;
//	Player player1;
//
//
//	//Welcome Message
//	cout << "Hello and welcome to POWER GRID V1.0\n\n" ;
//
//	//Prompt users for number of players
//	numOfPlayers = player1.promptForNumOfPlayers();
//
//	cout << "The number of players are: " << numOfPlayers << endl << endl ;
//
//	//Create players
//	//player1.promptPlayerForName();
//
//
//	Player *players = new Player[numOfPlayers];
//	//Enter player information
//	for (int i = 0 ; i < numOfPlayers ; i++)
//		players[i].promptPlayerForName();
//
//
//	//GARBAGE COLLECTION
//	//delete players;
///*
//	for (int i = 0 ; i < numOfPlayers ; i++)
//		delete players[i];
//		//players[i].~Player();
//*/
//
//
//	//exit call and pause
//	string anykey;
//	cout << "Press any key to continue";
//	cin >> anykey;

    Map g = Map();
    Vertex v = Vertex("Montreal", "Canada");
    Vertex u = Vertex("Toronto", "Canada");
    Vertex w = Vertex("New York", "USA");
    g.addVertex(u);
    g.addVertex(v);
    g.addVertex(w);
    g.addEdge(u, v, 10);
    g.addEdge(v, w, 12);
    cout << g;
    cout << g.BFS(v);
	return 0;
}// close main loop