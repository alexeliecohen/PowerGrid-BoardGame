//
// Created by alext on 2/7/2019.
//

#include <iostream>
#include "Houses.h"

Houses::Houses() {
   std::cout<<"House object created." << std::endl;
}
Houses::Houses(int numbHouses, enum houseColor color) {
    this->numbHouses = numbHouses;
     myColor = color;
}
void Houses::IncrHouses()  {
    this->numbHouses++;
}
Houses::~Houses() {
    std::cout << "House object terminated"<< std::endl;}
int Houses::getNumbHouses() const  {
    return this->numbHouses;
}
houseColor Houses::getHouseColor() const { return this->myColor;}
Houses& Houses::operator++() {
    this->numbHouses++;
}
ostream& operator<<(ostream& outs,const Houses& theObject) {
    outs << "Numb Houses: " << theObject.getNumbHouses() << " Color:" << theObject.getHouseColor();
}