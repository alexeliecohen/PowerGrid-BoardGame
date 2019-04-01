
//
// Created by alext on 2/7/2019.
//
#include <iostream>
#include "Card.h"
#include <string>

#ifndef POWERPLANT_POWERPLANT_H
#define POWERPLANT_POWERPLANT_H

/**
 *
 */
class Powerplant : public Card {
private:
    int priceCost, energyCost, productionValue, powerPlantNumber, bidValue;
    std::string resourceType;
    static int number;
public:
    /**
     * Default constructor for the powerplant object
     */
    Powerplant();

    /**
     * Copy constructor for the powerplant object
     * @param p2 The powerplant you want to copy
     */
    Powerplant(const Powerplant &p2);

    /**
     * Fully Parametrized constructor for building the Powerplant class
     * @param priceCost Initial cost of the powerplant
     * @param energyCost Required elektro to produce power
     * @param productionValue Amount of energy produced from the provided eletro
     * @param resourceType The type of resource used for the powerplant.
     */
    Powerplant(int priceCost, int energyCost, int productionValue, std::string resourceType);

    Powerplant &operator=(const Powerplant &p1);

    /**
     * Default destructor for the object
     */
    ~Powerplant();

    /**
     * Get the name of the resource used for the powerplant
     * @return resource type
     */
    const std::string &getResourceType() const;

    /**
     * Getter for the price cost
     * @return Powerplant cost
     */
    int getPriceCost() const;

    /**
     * Getter for the energy cost of the powerplant
     * @return integer represnting the amount of energy the plant conumes
     */
    int getEnergyCost() const;

    /**
     * Getter for the production value of the powerplant
     * @return integer representing the quantity of homes it powers
     */
    int getProductionValue() const;

    /**
     * toString method for the class
     * @param stream
     * @return stream of data for the output
     */
    virtual std::ostream &toString(std::ostream &stream);

    /**
     * Checks for equality between two powerplants by comparing the
     * price cost, energy cost, production value, and powerplant number.
     * @param p1
     * @return boolean value to see if values are equal
     */
    bool operator==(const Powerplant &p1) const;

    /**
     * Checks if one powerplant is less than the other
     * @param p1
     * @return Boolean value to see if the current powerplant is less than the other
     */
    bool operator<(Powerplant &p1);

    /**
     *Method to generate power for the powerplant based on the resource type
     * and cost.
     * @return value representing the number of houses it will power.
     */
    int generatePower();

    /**
     * Getter method for the current bid of the powerplant
     * @return Integer representing the highest placed bid for the powerplant
     */
    int getBidValue() const;

    /**
     * Setter method to update the current bid value of the powerplant
    * @param bidValue takes integer value representing the highest placed bid,
    * will not update if the bid is lower than the currentbid value
    */
    void setBidValue(int bidValue);


};

#endif //POWERPLANT_POWERPLANT_H
