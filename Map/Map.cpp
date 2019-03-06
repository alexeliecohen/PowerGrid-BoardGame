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

//TODO finish BFS
bool Map::BFS(Vertex v) {
    std::vector<Vertex> level;
    std::vector<Vertex> known;
    level.push_back(v);
    known.push_back(v);
    while(!level.empty()) {
        std::vector<Vertex> nextLevel;
        for(int i = 0; i < level.size(); i++) {
            for(int j = 0; j < level.at(i).getEdges()->size(); j++) {
                Vertex u = opposite(level.at(i), level.at(i).getEdges()->at(j));
                if(std::find(known.begin(), known.end(), u) != std::end(known)) {
                    known.push_back(u);
                    nextLevel.push_back(u);
                }
            }
        }
        level = nextLevel;
    }
    return level.size() == numVertex();
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
