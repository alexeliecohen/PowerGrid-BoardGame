//
// Created by alext on 2/7/2019.
//

#include "Powerplant.h"


Powerplant::Powerplant(int priceCost, int energyCost, int productionValue, std::string resourceType) {
    Card();
//    powerPlantNumber = powerplants;
//    powerplants++;
    this->priceCost = priceCost;
    this->energyCost = energyCost;
    this->productionValue = productionValue;
    this->resourceType= resourceType;
}
Powerplant::Powerplant() {}

Powerplant::Powerplant(const Powerplant &p2) {
    priceCost = p2.priceCost;
    energyCost = p2.energyCost;
    productionValue = p2.productionValue;
    resourceType = p2.resourceType;
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
//    stream << "Powerplant #: " << powerPlantNumber
    stream << " Cost: " << priceCost << " Energy Consumption: " << energyCost <<
           resourceType << " and Powers " << productionValue << " cities" << std::endl;
    return stream;
}
//std::ostream& operator<<(std::ostream& stream, Powerplant &somePowerplant) {
//   return somePowerplant.toString(stream);
//}

