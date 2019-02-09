//
// Created by alext on 2/7/2019.
//
#include <iostream>
#include "Resource.h"
#ifndef POWERPLANT_POWERPLANT_H
#define POWERPLANT_POWERPLANT_H
//using namespace std;
// enum class: string{coal="coal",oil="oil",garbage="garbage",uranium="uranium",hybdrid,ecological};
//use enum instead ?
class Powerplant {
    private:
        int priceCost,energyCost,productionValue;
        Resource myResource;


//        PType myPowerplant;
    public:
        Powerplant();
        Powerplant(int priceCost,int energyCost,int productionValue, Resource myResource);
        ~Powerplant();
        int  getPrice() const;
        int getEnergyCost() const;
        int getProductionValue() const;
        friend std::ostream& operator<<(std::ostream& stream, Powerplant& somePowerplant);
};

#endif //POWERPLANT_POWERPLANT_H
