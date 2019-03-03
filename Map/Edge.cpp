//
// Created by Hubert on 2/9/2019.
//

#include "Edge.h"

Edge::Edge() {
    endpoints = new std::vector<Vertex>();
    cost = 0;
}

Edge::Edge(Vertex &u, Vertex &v, int &cost) {
    endpoints = new std::vector<Vertex>();
    endpoints->push_back(u);
    endpoints->push_back(v);
    this->cost = cost;
}

Edge::Edge(const Edge &e) {
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
}

int Edge::getCost() {
    return cost;
}

std::vector<Vertex>* Edge::getEndpoints() {
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