//
// Created by Hubert on 2/9/2019.
//

#include "Vertex.h"
#include <iostream>
#include <string>

/**
 * Constructor for a Vertex
 */
Vertex::Vertex() {
    region = "none";
    name = "none";
    cost[0] = 10;
    cost[1] = 15;
    cost[2] = 20;
    playerCount = 0;
    for(int i = 0; i < players->size(); i++) {
        players[i] = "none";
    }
    edges = new std::vector<Edge>();
}

/**
 * Parameterized constructor for a Vertex
 * @param name the name of the city
 * @param region the region the city is in
 */
Vertex::Vertex(const std::string name, const std::string region) {
    this->region = region;
    this->name = name;
    cost[0] = 10;
    cost[1] = 15;
    cost[2] = 20;
    playerCount = 0;
    for(int i = 0; i < players->size(); i++) {
        players[i] = "none";
    }
    edges = new std::vector<Edge>();
}

/**
 * Copy constructor for a vertex
 * @param v The vertex to be copied
 */
Vertex::Vertex(const Vertex &v) {
    region = v.region;
    name = v.name;
    for(int i = 0; i < 3; i++) {
        cost[i] = v.cost[i];
    }
    playerCount = v.playerCount;
    for (int i = 0; i < v.players->size(); i++) {
        players[i] = v.players[i];
    }
    if(v.edges) {
        edges = new std::vector<Edge>();
        edges = v.edges;
    }
    else {
        edges = nullptr;
    }
}

/**
 * Getter for the edges
 * @return the set of edges adjacent to this vertex
 */
std::vector<Edge>* Vertex::getEdges() {
    return edges;
}

/**
 * Getter for the cost of placing a house
 * @return the cost of placing a house
 */
int Vertex::getCost() {
    return cost[playerCount];
}

/**
 * Getter for the region
 * @return the region the city is in
 */
std::string Vertex::getRegion() const {
    return region;
}

/**
 * Getter for the playerCount
 * @return the number of players who have a house placed on this city
 */
int Vertex::getPlayerCount() {
    return playerCount;
}

/**
 * Getter for the player
 * @param i which player to return
 * @return the specified player on this city
 */
std::string Vertex::getPlayer(const int i) {
    return players[i];
}

/**
 * Getter for the name
 * @return the name of the city
 */
std::string Vertex::getName() const {
    return name;
}

/**
 * Operator overload for assignment operator
 * @param v a Vertex
 * @return a reference to the copied vertex
 */
Vertex& Vertex::operator=(const Vertex &v) {
    if(this == &v) {
        return *this;
    }
    delete edges;
    playerCount = v.playerCount;
    name = v.name;
    region = v.region;
    for(int i = 0; i < 3; i++) {
        cost[i] = v.cost[i];
    }
    for(int i = 0; i < v.players->size(); i++) {
        players[i] = v.players[i];
    }
    if(v.edges) {
        edges = new std::vector<Edge>();
        edges = v.edges;
    }
    else {
        edges = nullptr;
    }
    return *this;
}

/**
 * Operator overload for the equality condition
 * returns true if the vertices have the same attributes
 * @param v a Vertex
 * @return whether or not the two vertices are equal
 */
bool Vertex::operator==(const Vertex &v) {
    return playerCount == v.playerCount && name == v.name && region == v.region && edges == v.edges;
}

/**
 * Operator overload for the output stream
 * @param os an output stream
 * @param v a Vertex
 * @return ouputs the Vertex in string format
 */
std::ostream &operator<<(std::ostream &os, const Vertex v) {
    os << v.getName() << ", " << v.getRegion() << "\n";
    return os;
}

/**
 * Adds an adjacent edge to this vertex
 * @param e the edge to be added
 */
void Vertex::addEdge(Edge e) {
    edges->push_back(e);
}
