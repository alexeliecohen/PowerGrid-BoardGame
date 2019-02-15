/*
 * ResourceMarket.h
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

#ifndef RESOURCEMARKET_H_
#define RESOURCEMARKET_H_

namespace Mike2 {

class ResourceMarket {
private:
	//Attributes
	int oil;
	int coal;
	int garbage;
	int uranium;
public:
	//Methods
	void addOil();
	void addOil(int amt);
	void removeOil();
	void removeOil(int amt);
	int getOil();
	void addCoal();
	void addCoal(int amt);
	void removeCoal();
	void removeCoal(int amt);
	int getCoal();
	void addGarbage();
	void addGarbage(int amt);
	void removeGarbage();
	void removeGarbage(int amt);
	int getGarbage();
	void addUranium();
	void addUranium(int amt);
	void removeUranium();
	void removeUranium(int amt);
	int getUranium();

	int getCoalPrice();
	int getOilPrice();
	int getGarbagePrice();
	int getUraniumPrice();

	//Constructors / Destructors
	ResourceMarket();
	virtual ~ResourceMarket();


};

} /* namespace Mike */

#endif /* RESOURCEMARKET_H_ */
