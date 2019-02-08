/*
 * ResourceMarket.cpp
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 445
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 */

#include "ResourceMarket.h"

namespace Mike {


//Attributes
int oil;
int coal;
int garbage;
int uranium;

//Constructors
ResourceMarket::ResourceMarket() {oil=13;	coal=13;	garbage = 13;	uranium = 13;}

ResourceMarket::~ResourceMarket() {}

//Methods
void addOil() {oil++;}
void addOil(int amt){oil+=amt;}
void removeOil(){oil--;}
void removeOil(int amt){oil-=amt;}
int getOil(){return oil;}
void addCoal(){coal++;}
void addCoal(int amt){coal+=amt;}
void removeCoal(){coal--;}
void removeCoal(int amt){coal-=amt;}
int getCoal(){return coal;}
void addGarbage(){garbage++;}
void addGarbage(int amt){garbage+=amt;}
void removeGarbage(){garbage--;};
void removeGarbage(int amt){garbage-=amt;};
int getGarbage(){return garbage;}
void addUranium(){uranium++;}
void addUranium(int amt){uranium+=amt;}
void removeUranium(){uranium--;}
void removeUranium(int amt){uranium-=amt;};
int getUranium(){return uranium;}

int getCoalPrice() {
	int price;
	price =
	return price;
};
int getOilPrice();
int getGarbagePrice();
int getUraniumPrice();

} /* namespace Mike */
