
//
// Created by alext on 2/7/2019.
//

#include "Powerplant.h"
using namespace std;

int Powerplant::number =0;
Powerplant::Powerplant(int priceCost, int energyCost,int productionValue, std::string resourceType) {
    Card();
    powerPlantNumber = number;
    number++;
    this->priceCost = priceCost;
    this->energyCost = energyCost;
    this->productionValue = productionValue;
    this->resourceType= resourceType;
    bidValue = priceCost;
    if(energyCost != 0) {
        this->priority = productionValue / energyCost;
    }
    else {
        this->priority = 0;
    }
}
Powerplant::Powerplant() {}

Powerplant::Powerplant(const Powerplant &p2) {
    //copy constructor for the object set all the attributes to the other object
    powerPlantNumber = p2.powerPlantNumber;
    priceCost = p2.priceCost;
    energyCost = p2.energyCost;
    productionValue = p2.productionValue;
    resourceType = p2.resourceType;
    bidValue = p2.priceCost;
    priority = p2.priority;
}

Powerplant& Powerplant::operator=(const Powerplant& p1) {
    //set all the attributes of the new object to the other objects
    powerPlantNumber = p1.powerPlantNumber;
    priceCost = p1.priceCost;
    energyCost = p1.energyCost;
    productionValue = p1.productionValue;
    resourceType= p1.resourceType;
    bidValue = p1.bidValue;
    priority = p1.priority;
    return *this;
}

int Powerplant::getPriority() {
    return priority;
}

int Powerplant::getEnergyCost() const {
    return this->energyCost;
}

int Powerplant::getProductionValue() const {
    return this->productionValue;
}

Powerplant::~Powerplant() {}


int Powerplant::getPriceCost() const {
    return priceCost;
}

const std::string &Powerplant::getResourceType() const {
    return resourceType;
}

std::ostream& Powerplant::toString(std::ostream& stream) {
    //output to cout the attributes of the class
    stream << "Powerplant #: " << powerPlantNumber << endl;
    stream << "Cost: " << priceCost << " Elektro, " << " Energy Consumption: " << energyCost << " ";
    //if the powerplant is a hybrid then output this additional string
    if (resourceType == "Hybrid") {
        stream << "combination of Coal/Oil";
    }
    //return the rest of the class attributes
    stream << resourceType << ", and Powers " << productionValue << " cities." << std::endl;
    //return the stream
    return stream;
}

bool Powerplant::operator==(const Powerplant& p1) const {
    //check if both powerplants are equal based on all attributes
    return(priceCost==p1.priceCost && energyCost == p1.energyCost && productionValue == p1.productionValue && resourceType==p1.resourceType);

}
bool Powerplant::operator<(Powerplant &p1) {
    //check if powerplant is less than the other based on the number on the card
    return this->priceCost < p1.priceCost;
}

int Powerplant::getBidValue() const {
    return bidValue;
}

void Powerplant::setBidValue(int bidValue) {
    Powerplant::bidValue = bidValue;
}
