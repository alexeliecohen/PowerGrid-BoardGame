//
// Created by alext on 2/7/2019.
//
#include <string>
#include <iostream>
#include <vector>

#ifndef POWERPLANT_HOUSES_H
#define POWERPLANT_HOUSES_H
using namespace std;

class Houses {
private:
    string myColor;
    int houseCost;
    string owner;
    string city;

public:
    Houses(int houseCost,string myColor,string owner);

    Houses(int houseCost,string myColor,string owner,string city);

    Houses();

    ~Houses();

    const string &getMyColor() const;

    int getHouseCost() const;

    const string &getOwner() const;

    const string &getCity() const;

    void setMyColor(const string &myColor);

    void setHouseCost(int houseCost);

    void setOwner(const string &owner);

    void setCity(const string &city);

    friend ostream &operator<<(ostream &outs, const Houses &theObject);

    bool operator==(const Houses& h1);

};


#endif //POWERPLANT_HOUSES_H
