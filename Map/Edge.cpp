//
// Created by Hubert on 2/9/2019.
//

#include "Edge.h"
#include <iostream>
#include <string>

Edge::Edge() {
    endpoints = new Vertex[2];
    cost = 0;
}

Edge::Edge(Vertex &u, Vertex &v, int cost) {
    endpoints = new Vertex[2];
    endpoints[0] = u;
    endpoints[1] = v;
    this->cost = cost;
}

Edge::Edge(const Edge &e) {
    cost = e.cost;
    endpoints = new Vertex[2];
    for(int i = 0; i < 2; i++) {
        endpoints[i] = e.endpoints[i];
    }
}

int Edge::getCost() const {
    return cost;
}

Vertex * Edge::getEndpoints() const {
    return endpoints;
}

Edge &Edge::operator=(const Edge &e) {
    if(this == &e) {
        return *this;
    }
    cost = e.cost;
    for(int i = 0; i < 2; i++) {
        endpoints[i] = e.endpoints[i];
    }
    return *this;
}

bool Edge::operator==(const Edge &e) {
    if(cost != e.cost) {
        return false;
    }
//    if(endpoints == e.endpoints) {
//        return true;
//    }
//    for(int i = 0; i < endpoints->size(); i++) {
//        if(endpoints[i] != e.endpoints[i]) {
//            return false;
//        }
//    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Edge &e) {
    Vertex* endpoints = e.getEndpoints();
    os << endpoints[0].getName() << " -> " << endpoints[1].getName() << ", " << e.getCost() << "\n";
    return os;
}
