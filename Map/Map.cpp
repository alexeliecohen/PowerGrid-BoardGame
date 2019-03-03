//
// Created by Hubert on 2/9/2019.
//

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"

Map::Map() {
    vertices = new std::vector<Vertex>();
    edges = new std::vector<Edge>();
}

Map::Map(const Map &m) {

}

void Map::addVertex(Vertex v) {
    vertices->push_back(v);
}

void Map::addEdge(Vertex u, Vertex v, int cost) {
    Edge e(u, v, cost);
    u.getEdges()->push_back(e);
    v.getEdges()->push_back(e);
    edges->push_back(e);
}

bool Map::BFS(Vertex v) {
    return false;
}