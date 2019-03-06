//
// Created by Hubert on 2/9/2019.
//

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"
#include<list>
#include <iostream>
#include <algorithm>

Map::Map() {
    vertices = new std::vector<Vertex>();
    edges = new std::vector<Edge>();
}

void Map::addVertex(Vertex v) {
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

Vertex Map::opposite(Vertex v, Edge e) {
    Vertex* endpoints = e.getEndpoints();
    if(endpoints[0] == v) {
        return endpoints[1];
    }
    else {
        return endpoints[0];
    }
}

bool Map::BFS(Vertex &s) {
    auto level = std::vector<Vertex>();
    auto known = std::vector<Vertex>();
    level.push_back(s);
    known.push_back(s);
    while(!level.empty()) {
        auto nextLevel = std::vector<Vertex>();
        for(auto &u : level) {
            for(auto &e : *getVertexEdges(u)) {
                Vertex v = opposite(u, e);
                if(!(std::find(known.begin(), known.end(), v) != known.end())) {
                    known.push_back(v);
                    nextLevel.push_back(v);
                }
            }
        }
        level = nextLevel;
    }
    return known.size() == numVertex();
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

Vertex* Map::findVertex(std::string s) {
    for(int i = 0; i < vertices->size(); i++) {
        Vertex v = vertices->at(i);
        if(v.getName() == s ) {
            return &v;
        }
    }
    return nullptr;
}
