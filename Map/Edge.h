//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_EDGE_H
#define COMP345TEAM21_EDGE_H

#include <vector>
#include "Vertex.h"

class Vertex;

class Edge {
public:
    Edge();
    Edge(Vertex &u, Vertex &v, int cost);
    Edge(const Edge &e);
    Edge& operator=(const Edge &e);
    std::vector<Vertex>* getEndpoints() const;
    int getCost() const;
    bool operator==(const Edge &e);
    friend std::ostream& operator<<(std::ostream& os, const Edge &e);
private:
    std::vector<Vertex> *endpoints;
    int cost;
};

#endif //COMP345TEAM21_EDGE_H
