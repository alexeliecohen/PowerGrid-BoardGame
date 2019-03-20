//
// Created by alext on 2/7/2019.
//

#include "Resource.h"
<<<<<<< HEAD
=======
#include <string>
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2

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


