//
// Created by alext on 2/7/2019.
//

#include "Powerplant.h"

Powerplant::Powerplant(int priceCost, int energyCost, int productionValue, Resource myResource) {
    this->priceCost = priceCost;
    this->energyCost = energyCost;
    this->productionValue = productionValue;
    this->myResource = myResource;
}
Powerplant::Powerplant() {}

int Powerplant::getEnergyCost() const {
    return this->energyCost;
}
int Powerplant::getPrice() const {
    return this->priceCost;
}
int Powerplant::getProductionValue() const {
    return this->productionValue;
}
std::ostream& operator<<(std::ostream &stream, Powerplant &somePowerplant) {
    stream << "Powerplant Cost: " << somePowerplant.priceCost << " Energy Consumption: " << somePowerplant.energyCost <<
    somePowerplant.myResource.getResourceType() << " and Powers " << somePowerplant.productionValue << " cities";
}
Powerplant::~Powerplant() {}