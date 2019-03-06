//
// Created by alext on 2/7/2019.
//

#include "Resource.h"

 Resource::Resource() {}
 Resource::Resource(int cost, int amount, string resourceType) {
    this->cost=cost;
    this->amount=amount;
    this->resourceType=resourceType;
}
Resource::Resource(string resourceType) {
    this->resourceType = resourceType;
}
Resource::~Resource() {
    cout << "object being destroyed" << endl;
}
ostream& operator<<(ostream& out,Resource& someResource) {
    out << someResource.amount << " " << someResource.resourceType << ", Costing" << someResource.cost << " electro each";
    return  out;
}


