//
// Created by alext on 2/7/2019.
//
//#include "Powerplant.h"
#include <iostream>
#ifndef POWERPLANT_RESOURCE_H
#define POWERPLANT_RESOURCE_H

class Resource {
private:
    std::string resourceType;
    int cost,amount;
public:
    Resource(std::string resourceType);
    Resource();
    Resource(int cost,int amount,std::string resourceType);
    ~Resource();
    std::string getResourceType() const;
    int getCost() const;
    int getAmount() const;
    friend std::ostream& operator<<(std::ostream& out,Resource& someResource);
};
class Coal:public Resource {
public:
    Coal();
    Coal(int cost,int amount);
};
class Oil: public Resource {
public:
    Oil();
    Oil(int cost,int amount);
};

class Uranium: public Resource {
    public:
    Uranium();
    Uranium(int cost,int amount);
};

class Garbage: public Resource {
public:
    Garbage();
    Garbage(int cost,int amount);
};

class Ecological: Resource {
public:
    Ecological();
    Ecological(int cost,int amount);

};

#endif //POWERPLANT_RESOURCE_H
