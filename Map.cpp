//
// Created by Hubert on 2/9/2019.
//

#include "Map.h"

Map::Map() {
    Map(false);
}

Map::Map(bool isDirected) {
    this->isDirected = isDirected;
}

//TODO implement copy constructor
Map::Map(Map &m) {

}

//TODO implement destructor
Map::~Map() {

}

//TODO implement operator overload
Map &Map::operator=(Map &m) {

}

int Map::numVertices() {
    return vertices.size();
}

std::list<Vertex> Map::getVertices() {
    return std::list<Vertex>();
}

int Map::numEdges() {
    return edges.size();
}

std::list<Edge> Map::getEdges() {
    return std::list<Edge>();
}

int Map::outDegree(Vertex v) {
    return v.getOutgoing().size();
}

//TODO switch map to vector
std::vector<Edge> Map::outgoingEdges(Vertex v) {

}

int Map::inDegree(Vertex v) {
    return v.getIncoming().size();
}

//TODO switch map to vector
std::vector<Edge> Map::incomingEdges(Vertex v) {
    return std::vector<Edge>();
}

Edge Map::getEdge(Vertex u, Vertex v) {
    return u.getOutgoing().at(v);
}

Vertex *Map::endVertices(Edge e) {
    return e.getEndpoints();
}

//TODO implement method
Vertex Map::opposite(Vertex v, Edge e) {
    //return Vertex();
}

Vertex Map::insertVertex(int &city) {
    Vertex v(city, false);
    vertices.push_back(v);
}

//TODO check for already existing edge
Edge Map::insertEdge(Vertex u, Vertex v, int cost) {
    Edge e(u, v, cost);
    edges.push_back(e);
    u.getOutgoing().insert(u.getOutgoing().begin(), u.getOutgoing().find(v));
    v.getOutgoing().insert(v.getOutgoing().begin(), v.getOutgoing().find(u));
    return e;
}

void Map::removeVertex(Vertex v) {

}
