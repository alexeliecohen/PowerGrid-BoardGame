//
// Created by alext on 2/7/2019.
//
#include <iostream>
#ifndef POWERPLANT_RESOURCE_H
#define POWERPLANT_RESOURCE_H
using namespace std;

class Resource {
private:
    string resourceType;
    int cost,amount;
public:
    Resource(string resourceType);
    Resource();
    Resource(int cost,int amount,string resourceType);
    ~Resource();
    string getResourceType() const;
    int getCost() const;
    int getAmount() const;
    friend ostream& operator<<(ostream& out,Resource& someResource);
    bool operator==(const Resource& r1);
};


#endif //POWERPLANT_RESOURCE_H
