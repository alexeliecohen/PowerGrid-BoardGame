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
ResourceMarket::ResourceMarket() {oil=18;	coal=24;	garbage = 6;	uranium = 2;}

ResourceMarket::~ResourceMarket() {}

//Methods
void addOil() {
	if (oil<24)
		oil++;
	else
		std::cout << "\nThere is no supply left of oil to add to the resource market\n" ;
}//close add oil1
void addOil(int amt){
	if (oil+amt <= 24)
		oil+=amt;
	else {
		std::cout << "\nThere is no supply left of oil to add to the resource market\n" ;
		oil = 24;
	}//close else no oil supply left
}//close add oil2
void removeOil(){
	if (oil>0)
			oil--;
		else
			std::cout << "\nThere is no oil left in the resource market\n" ;
}//close remove oil
void removeOil(int amt){
	if (oil-amt >= 0)
			oil-=amt;
		else {
			std::cout << "\nThere is no oil left in the resource market\n" ;
			oil = 0;
		}//close else no oil supply left
}//close remove oil 2
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
