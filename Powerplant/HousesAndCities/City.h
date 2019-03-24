
//
// Created by alext on 2/7/2019.
//

#include "Houses.h"
#ifndef POWERPLANT_CITY_H
#define POWERPLANT_CITY_H


class City {
private:
    int accessCost;
    string name;
    Houses myHouses[3];
public:
    City(int accessCost,Houses Homes[]);
    City (int accessCost,std::string name);
    ~City();

    const string &getName() const;

    const Houses *getMyHouses() const;

    int getAccessCost() const;

    void setAccessCost(int accessCost);

    void setName(const string &name);

    friend ostream& operator <<(ostream& stream,City& Object);


};


#endif //POWERPLANT_CITY_H