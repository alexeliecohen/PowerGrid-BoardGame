//
// Created by alext on 2/7/2019.
//

#include "Resource.h"
 Resource::Resource() {}
 Resource::Resource(int cost, int amount, std::string resourceType) {
    this->cost=cost;
    this->amount=amount;
    this->resourceType=resourceType;
}
Resource::Resource(std::string resourceType) {
    this->resourceType = resourceType;
}
Resource::~Resource() {
    std::cout << "object being destroyed" << std::endl;
}
int Resource::getAmount() const {
    return this->amount;
}
int Resource::getCost() const {
    return this->cost;
}
std::string Resource::getResourceType() const {
    return this->resourceType;
}

Coal::Coal() {
    Resource("Coal");
}
Coal::Coal(int cost,int amount) {
    Resource(cost,amount,"Coal");
}
Oil::Oil() {
    Resource("Oil");
}
Oil::Oil(int cost,int amount) {
    Resource(cost,amount,"Oil");
}
Uranium::Uranium() {
    Resource("Uranium");
}
Uranium::Uranium(int cost,int amount) {
    Resource(cost,amount,"Uranium");
}
Garbage::Garbage() {
    Resource("Garbage");
}
Garbage::Garbage(int cost,int amount) {
    Resource(cost,amount,"Garbage");
}
Ecological::Ecological() {
    Resource("Ecological");
}
Ecological::Ecological(int cost,int amount) {
    Resource(cost,amount,"Ecological");
}
std::ostream& operator<<(std::ostream& out,Resource& someResource) {
    if (someResource.cost != 0 && someResource.amount!=0) {
        out << someResource.amount << " " << someResource.resourceType << ", Costing" << someResource.cost << " electro each";
    }
    else {
        out << someResource.resourceType;
    }
    return  out;
}


