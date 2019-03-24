
//
// Created by alext on 2/7/2019.
//

#include "City.h"
using namespace std;

int City::getAccessCost() const {
    return accessCost;
}

const string &City::getName() const {
    return name;
}

const Houses *City::getMyHouses() const {
    return myHouses;
}

void City::setAccessCost(int accessCost) {
    City::accessCost = accessCost;
}

void City::setName(const string &name) {
    City::name = name;
}

ostream& operator <<(ostream& stream,City& Object) {
    stream << "City Name: " << Object.name << "/nAccess Cost: " << Object.accessCost;
    if (Object.myHouses == 0) {
        stream << "/nNo Homes" << endl;
    }
    else {
        for (int i = 0; i < 3; ++i) {
            stream << "House #" << i << ": " <<Object.myHouses[i] << "/n";
        }
    }
    return stream;
}