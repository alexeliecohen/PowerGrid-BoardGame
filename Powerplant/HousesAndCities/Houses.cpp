
//
// Created by alext on 2/7/2019.
//

#include "Houses.h"

Houses::Houses() {
   cout<<"House object created." << endl;
}
Houses::Houses(int houseCost, std::string myColor, std::string owner) {
    this->houseCost = houseCost;
    this->myColor = myColor;
    this->owner = owner;
}

Houses::Houses(int houseCost,string myColor,string owner,string city) {
    this->houseCost = houseCost;
    this->myColor = myColor;
    this->owner = owner;
    this->city = city;
}

Houses::~Houses() {}

ostream& operator<<(ostream& outs,const Houses& theObject) {
    outs << "Owner: " << theObject.owner << " City: " << theObject.city << " Cost: "
    << theObject.houseCost << " Color: " << theObject.myColor << endl;
    return outs;
}

const string &Houses::getMyColor() const {
    return myColor;
}

int Houses::getHouseCost() const {
    return houseCost;
}

const string &Houses::getOwner() const {
    return owner;
}

const string &Houses::getCity() const {
    return city;
}

void Houses::setMyColor(const string &myColor) {
    Houses::myColor = myColor;
}

void Houses::setHouseCost(int houseCost) {
    Houses::houseCost = houseCost;
}

void Houses::setOwner(const string &owner) {
    Houses::owner = owner;
}

void Houses::setCity(const string &city) {
    Houses::city = city;
}

bool Houses::operator==(const Houses& h1) {
    return (houseCost == h1.houseCost && city==h1.city && owner == h1.owner && myColor == h1.myColor);
}