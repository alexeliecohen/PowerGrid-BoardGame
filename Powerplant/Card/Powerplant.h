//
// Created by alext on 2/7/2019.
//
#include <iostream>
#include "Card.h"
#include <string>

#ifndef POWERPLANT_POWERPLANT_H
#define POWERPLANT_POWERPLANT_H


class Powerplant : public Card {
private:
    int priceCost, energyCost, productionValue, powerPlantNumber;
    std::string resourceType;
public:
    Powerplant();

     Powerplant(const Powerplant &p2);

    Powerplant(int priceCost, int energyCost, int productionValue, std::string resourceType);

    ~Powerplant();

    const std::string &getResourceType() const;

    int getPriceCost() const;

    int getEnergyCost() const;

    int getProductionValue() const;

    virtual std::ostream& toString(std::ostream& stream);

    bool operator==(Powerplant p1);

    int generatePower();

//    friend std::ostream &operator<<(std::ostream &stream, Powerplant &somePowerplant);

};

#endif //POWERPLANT_POWERPLANT_H
