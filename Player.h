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
 */

#include <string>
#include <iostream>


#ifndef PLAYER_H_
#define PLAYER_H_


namespace Mike {

class Player {
private:
	std::string playerName;
public:
	Player();
	Player(std::string);
	virtual ~Player();
	std::string getName();
	std::string toString();
	void setName(std::string);
	int promptForNumOfPlayers();
	void promptPlayerForName();
};//close player class.h

}; /* namespace Mike */

#endif /* PLAYER_H_ */
