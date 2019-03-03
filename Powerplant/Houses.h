//
// Created by alext on 2/7/2019.
//
#include <string>
#ifndef POWERPLANT_HOUSES_H
#define POWERPLANT_HOUSES_H
using namespace std;
enum houseColor {Green,Blue,Black,Pink,Yellow,Orange};

class Houses {
private:
    houseColor myColor;
    int numbHouses;
public:
    Houses(int numbHouses, enum houseColor color);

    Houses();

    ~Houses();

    void IncrHouses();

    int getNumbHouses() const;

    houseColor getHouseColor() const;

    Houses &operator++();

    friend ostream &operator<<(ostream &outs, const Houses &theObject);
};


#endif //POWERPLANT_HOUSES_H
