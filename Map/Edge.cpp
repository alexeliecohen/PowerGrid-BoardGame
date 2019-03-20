//
// Created by Hubert on 2/9/2019.
//

#include "Edge.h"
#include <iostream>
#include <string>

/**
 * Default constructor for an edge
 */
Edge::Edge() {
    endpoints = new Vertex[2];
    cost = 0;
}

/**
 * Parameterized constructor for an edge
 * @param u an adjacent Vertex
 * @param v another adjacent Vertex
 * @param cost the cost to travel this edge
 */
Edge::Edge(Vertex &u, Vertex &v, int cost) {
    endpoints = new Vertex[2];
    endpoints[0] = u;
    endpoints[1] = v;
    this->cost = cost;
}

/**
 * Copy constructor for an Edge
 * @param e the edge to be copied
 */
Edge::Edge(const Edge &e) {
    cost = e.cost;
    endpoints = new Vertex[2];
    for(int i = 0; i < 2; i++) {
        endpoints[i] = e.endpoints[i];
    }
}

/**
 * Getter for the cost of the edge
 * @return the cost of the edge
 */
int Edge::getCost() const {
    return cost;
}

/**
 * Getter for the endpoints of this edge
 * @return an array with both endpoints of this edge
 */
Vertex* Edge::getEndpoints() const {
    return endpoints;
}

/**
 * Operator overload for the assignment operator
 * @param e an Edge
 * @return the copied edge
 */
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

/**
 * Operator overload for the equality condition
 * @param e an edge
 * @return  whether the two edges are equal
 */
bool Edge::operator==(const Edge &e) {
    return cost == e.cost;
}

/**
 * Operator overload for the output stream
 * @param os an output stream
 * @param e an edge
 * @return prints the edge as a string
 */
std::ostream &operator<<(std::ostream &os, const Edge &e) {
    Vertex* endpoints = e.getEndpoints();
    os << endpoints[0].getName() << " -> " << endpoints[1].getName() << ", " << e.getCost() << "\n";
    return os;
}
