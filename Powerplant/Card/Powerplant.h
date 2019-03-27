<<<<<<< HEAD
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
    static int number;
public:
    Powerplant();

    Powerplant(const Powerplant &p2);

    Powerplant(int priceCost, int energyCost, int productionValue, std::string resourceType);

    ~Powerplant();

    const std::string &getResourceType() const;

    int getPriceCost() const;

    int getEnergyCost() const;

    int getProductionValue() const;

    virtual std::ostream &toString(std::ostream &stream);

    bool operator==(const Powerplant &p1) const;

    bool operator<(Powerplant &p1);

    int generatePower();



//    friend std::ostream &operator<<(std::ostream &stream, Powerplant &somePowerplant);

};

#endif //POWERPLANT_POWERPLANT_H
=======
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
// copy cosntructor for poweplant
     Powerplant(const Powerplant &p2);
//fully parametrized constructor for class
    Powerplant(int priceCost, int energyCost, int productionValue, std::string resourceType);
//destructor
    ~Powerplant();

    const std::string &getResourceType() const;
//getter methods
    int getPriceCost() const;

    int getEnergyCost() const;

    int getProductionValue() const;
//overlaod operator for cout
    virtual std::ostream& toString(std::ostream& stream);
//equals overload operator
    bool operator==(Powerplant p1);
//generate power method
    int generatePower();

//    friend std::ostream &operator<<(std::ostream &stream, Powerplant &somePowerplant);

};

#endif //POWERPLANT_POWERPLANT_H
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2
