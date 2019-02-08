/*
 * Player.h
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

#include <string>
#include <iostream>


#ifndef PLAYER_H_
#define PLAYER_H_


namespace Mike {

class Player {
private:
	static int numOfPlayers;
	std::string playerName;
	int elektros;
	int oil, coal, garbage, uranium;
	int numOfCities;

public:
	Player();
	Player(std::string);
	virtual ~Player();
	std::string getName();
	std::string toString();
	int getElektros();
	void setName(std::string);
	void setNumOfPlayers(int num);
	int getNumOfPlayers();
	void setElektros(int quantity);
	void addElektros(int quantity);
	void removeElektros(int quantity);
	int promptForNumOfPlayers();
	void promptPlayerForName();

	int getCoal();
	void addCoal();
	void addCoal(int add);
	void removeCoal();
	void removeCoal(int remove);
	int getGarbage();
	void addGarbage();
	void addGarbage(int add);
	void removeGarbage(int remove);
	void removeGarbage();
	int getOil();
	void addOil();
	void addOil(int add);
	void removeOil();
	void removeOil(int remove);
	int getUranium();
	void addUranium();
	void addUranium(int add);
	void removeUranium();
	void removeUranium(int add);
};
//close player class.h

}; /* namespace Mike */

#endif /* PLAYER_H_ */
