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
int numOfPlayers;
std::string playerName;
int elektros;
int oil, coal, garbage, uranium;
int numOfCities;
//Power plants?


//Constructors / Destructors
Player::Player() {elektros = 50; oil = 0; coal = 0; garbage = 0; uranium = 0; numOfCities = 0; }//close constructor
Player::Player(std::string nameIn) { playerName = nameIn; elektros = 50; oil = 0; coal = 0; garbage = 0; uranium = 0; numOfCities = 0; }//close constructor
Player::~Player() {}//close destructor

//Setters and Getters

std::string Player::getName() {return playerName;}
void setName(std::string nameIn) {playerName = nameIn;} //close set name
void setNumOfPlayers(int num) {numOfPlayers = num; }
int getNumOfPlayers() { return numOfPlayers; }
int getElektros() { return elektros; } //close get elektros
void setElektros(int quantity){ elektros = quantity; };
void addElektros(int quantity) { elektros += quantity; };
void removeElektros(int quantity) { elektros -= quantity; };
void addCity() { numOfCities++; };
int getCoal(){return coal; }
void addCoal() { coal++; }
void addCoal(int add) { coal += add; }
void removeCoal() { coal--; }
void removeCoal(int remove) { coal -= remove; }
int getGarbage() { return garbage; }
void addGarbage() { garbage++; }
void addGarbage(int add) { garbage += add; }
void removeGarbage(int remove) { garbage -= remove; }
void removeGarbage() { garbage--; }
int getOil() { return oil; }
void addOil() { oil++; }
void addOil(int add) { oil += add; };
void removeOil() { oil--; }
void removeOil(int remove) { oil -= remove; }
int getUranium() { return uranium; }
void addUranium() { uranium++; }
void addUranium(int add) {uranium += add; }
void removeUranium() { uranium--; }
void removeUranium(int add) {uranium -= add; }

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
