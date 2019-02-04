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
#include <string>
#include <iostream>

namespace Mike {

//Attributes
std::string playerName;

//Constructors / Destructors
Player::Player() {}//close constructor
Player::Player(std::string nameIn) { playerName = nameIn; }//close constructor
Player::~Player() {}//close destructor

//Setters and Getters
std::string Player::getName() {return playerName;}
void setName(std::string nameIn) {playerName = nameIn;} //close set name

//Other methods
//Prompt user number of players
int Player::promptForNumOfPlayers() {
	int numOfPlayers = 0;
	//Loop until numOfPlayers is a valid number
		while ( numOfPlayers < 2 || numOfPlayers > 6 ){
			std::cout << "Please enter the number of players that will be playing Power Grid?\n(Enter a number from 2 to 6 and press ENTER\n\n";

			// *****ERROR HANDLE FOR NON INTEGER TYPE INPUT
			std::cin >> numOfPlayers;

			//validate user input
			if ( numOfPlayers < 2 || numOfPlayers > 6 )
				std::cout << "THE NUMBER THAT YOU ENTERED IS INVALID\n only 2, 3, 4, 5 or players can play Power Grid\n\n" ;
		}//close while looking for valid number of players input
	return numOfPlayers;
}//close function prompt user

//Prompt user to input name
void Player::promptPlayerForName() {
	std::string pName = "THISstringShouldGETchanged";
	std::cout << "\nPlease enter the players name\n" ;
	std::cin >> pName ;
	playerName = pName;
}//close function prompt user

//To String method
std::string Player::toString() {
	std::string returnValue = ("\nThe Player's name is: " + playerName);
	return returnValue;
}//close tostring method



}//Close Namespace
