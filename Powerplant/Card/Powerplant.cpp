
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
}
Powerplant::Powerplant() {}

Powerplant::Powerplant(const Powerplant &p2) {
    powerPlantNumber = p2.powerPlantNumber;
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
    stream << "Powerplant #: " << powerPlantNumber << endl;
    stream << "Cost: " << priceCost << " Elektro, " << " Energy Consumption: " << energyCost << " ";

    if (resourceType == "Hybrid") {
        stream << "combination of Coal/Oil";
    } else {
       stream << resourceType << ", and Powers " << productionValue << " cities." << std::endl;
    }
    return stream;
}

bool Powerplant::operator==(const Powerplant& p1) const {
    return(priceCost==p1.priceCost && energyCost == p1.energyCost && productionValue == p1.productionValue && resourceType==p1.resourceType);

}
bool Powerplant::operator<(Powerplant &p1) {
    return this->priceCost < p1.priceCost;
}
