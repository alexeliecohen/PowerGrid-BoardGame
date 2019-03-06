//
// Created by Hubert on 2/9/2019.
//

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"
#include<list>
#include <iostream>

Map::Map() {
    vertices = new std::vector<Vertex>();
    edges = new std::vector<Edge>();
}

void Map::addVertex(std::string name, std::string region) {
    Vertex v(name, region);
    vertices->push_back(v);
}

void Map::addEdge(Vertex &u, Vertex &v, int cost) {
    Edge e(u, v, cost);
    u.addEdge(e);
    v.addEdge(e);
    edges->push_back(e);
}

int Map::numVertex() {
    return vertices->size();
}

int Map::numEdges() {
    return edges->size();
}

std::vector<Vertex>* Map::getVertices() {
    return vertices;
}

std::vector<Edge>* Map::getEdges() {
    return edges;
}

int Map::degree(Vertex v) {
    return v.getEdges()->size();
}

std::vector<Edge>* Map::getVertexEdges(Vertex v) {
    return v.getEdges();
}

//TODO finish BFS
bool Map::BFS(Vertex v) {
    std::list<Vertex> queue;
    std::vector<Vertex> known;
    queue.push_back(v);
    known.push_back(v);
    while(!queue.empty()) {
        v = queue.front();
        //TODO implement << overload
        //std::cout << v << " ";
        queue.pop_front();
        for(int i = 0; i < getVertexEdges(v)->size(); i++) {

        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, Map &m) {
    os << "Vertices:\n";
    for(int i = 0; i < m.numVertex(); i++) {
        os << m.getVertices()->at(i);
    }
    os << "\nEdges:\n";
    for(int i = 0; i < m.numEdges(); i++) {
        os << m.getEdges()->at(i);
    }
    return os;
}
