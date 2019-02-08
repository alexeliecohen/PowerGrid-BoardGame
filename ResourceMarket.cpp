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

#include <iostream>
#include <string>
#include "ResourceMarket.h"

namespace Mike2 {


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
	if (coal < 4 && coal!=0 )
		return 8;
	else if ( coal < 7 )
		return 7;
	else if ( coal < 10 )
		return 6;
	else if ( coal < 13 )
		return 5;
	else if ( coal < 16 )
		return 4;
	else if ( coal < 19 )
		return 3;
	else if ( coal < 22 )
		return 2;
	else if ( coal < 25 )
		return 1;
	else
		return 999999;
}//close get coal price
int getOilPrice(){
	if (oil < 4 && oil!=0 )
		return 8;
	else if ( oil < 7 )
		return 7;
	else if ( oil < 10 )
		return 6;
	else if ( oil < 13 )
		return 5;
	else if ( oil < 16 )
		return 4;
	else if ( oil < 19 )
		return 3;
	else if ( oil < 22 )
		return 2;
	else if ( oil < 25 )
		return 1;
	else
		return 999999;
}//close getOilPrice
int getGarbagePrice(){
	if (garbage < 4 && garbage!=0 )
		return 8;
	else if ( garbage < 7 )
		return 7;
	else if ( garbage < 10 )
		return 6;
	else if ( garbage < 13 )
		return 5;
	else if ( garbage < 16 )
		return 4;
	else if ( garbage < 19 )
		return 3;
	else if ( garbage < 22 )
		return 2;
	else if ( garbage < 25 )
		return 1;
	else
		return 999999;
}//close get garbage price
int getUraniumPrice(){
	if (uranium == 1)
		return 16;
	else if (uranium == 2)
		return 14;
	else if (uranium == 3)
		return 12;
	else if (uranium == 4)
		return 10;
	else if (uranium == 5)
		return 8;
	else if (uranium == 6)
		return 7;
	else if (uranium == 7)
		return 6;
	else if (uranium == 8)
		return 5;
	else if (uranium == 9)
		return 4;
	else if (uranium == 10)
		return 3;
	else if (uranium == 11)
		return 2;
	else if (uranium == 12)
		return 1;
	else
		return 999999;
}//close get uranium price

} /* namespace Mike */
