//
// Created by Hubert on 2/9/2019.
//

#include "Edge.h"
#include <iostream>
#include <string>

Edge::Edge() {
    endpoints = new std::vector<Vertex>();
    cost = 0;
}

Edge::Edge(Vertex &u, Vertex &v, int cost) {
    endpoints = new std::vector<Vertex>();
    endpoints->push_back(u);
    endpoints->push_back(v);
    this->cost = cost;
}

Edge::Edge(const Edge &e) {
    cost = e.cost;
//    if(e.endpoints) {
//        endpoints = new std::vector<Vertex>();
//        for(int i = 0; i < e.endpoints->size(); i++) {
//            endpoints[i] = e.endpoints[i];
//        }
//    }
//    else {
//        endpoints = 0;
//    }
}

int Edge::getCost() const {
    return cost;
}

std::vector<Vertex> * Edge::getEndpoints() const {
    return endpoints;
}

Edge &Edge::operator=(const Edge &e) {
    if(this == &e) {
        return *this;
    }
    delete endpoints;
    cost = e.cost;
    if(e.endpoints) {
        endpoints = new std::vector<Vertex>();
        for(int i = 0; i < e.endpoints->size(); i++) {
            endpoints[i] = e.endpoints[i];
        }
    }
    else {
        endpoints = 0;
    }
    return *this;
}

bool Edge::operator==(const Edge &e) {
    if(cost != e.cost) {
        return false;
    }
    if(endpoints == e.endpoints) {
        return true;
    }
//    for(int i = 0; i < endpoints->size(); i++) {
//        if(endpoints[i] != e.endpoints[i]) {
//            return false;
//        }
//    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Edge &e) {
    os << e.getCost() << "\n";
    return os;
}
