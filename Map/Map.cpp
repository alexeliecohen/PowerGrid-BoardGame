//
// Created by Hubert on 2/9/2019.
//
//TODO add comments

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <algorithm>

Map::Map() {
    vertices = std::vector<Vertex>();
    edges = std::vector<Edge>();
    regions = std::vector<std::string>();
    subgraphs = std::vector<Map>();
}

//TODO fix case where vertex already exists
void Map::addVertex(Vertex v) {
    if(!(std::find(vertices.begin(), vertices.end(), v) != vertices.end())) {
        vertices.push_back(v);
    }
    else {
        std::cout << "Vertex already exists";
    }
}

void Map::addEdge(Vertex &u, Vertex &v, int cost) {
    Edge e = Edge(u, v, cost);
    if(!(std::find(edges.begin(), edges.end(), e) != edges.end())) {
        u.addEdge(e);
        v.addEdge(e);
        edges.push_back(e);
    }
    else {
        std::cout << "Edge already exists";
    }
}

int Map::numVertex() {
    return vertices.size();
}

int Map::numEdges() {
    return edges.size();
}

std::vector<Vertex> Map::getVertices() {
    return vertices;
}

std::vector<Edge> Map::getEdges() {
    return edges;
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

bool Map::BFS() {
    auto level = std::vector<Vertex>();
    auto known = std::vector<Vertex>();
    level.push_back(vertices.at(0));
    known.push_back(vertices.at(0));
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
    os << "Regions:\n";
    for(const auto &r : m.getRegions()) {
        os << r << "\n";
    }
    os << "\nVertices:\n";
    for(int i = 0; i < m.numVertex(); i++) {
        os << m.getVertices().at(i);
    }
    os << "\nEdges:\n";
    for(int i = 0; i < m.numEdges(); i++) {
        os << m.getEdges().at(i);
    }
    os << "\n";
    return os;
}

//TODO what to return if vertex not found
Vertex Map::findVertex(std::string s) {
    for (const auto &v : vertices) {
        if(v.getName() == s ) {
            return v;
        }
    }
}

void Map::createSubgraphs() {
    int i = 0;
    for(const auto &r : regions) {
        Map g = Map();
        g.addRegion(r);
        for(const auto &v : vertices) {
            if(r == v.getRegion()) {
                g.addVertex(v);
            }
        }
        for(auto e : edges) {
            Vertex* endpoints = e.getEndpoints();
            if(endpoints[0].getRegion() == r && endpoints[1].getRegion() == r) {
                g.addEdge(e);
            }
        }
        subgraphs.push_back(g);
        i++;
    }
}

void Map::addRegion(std::string region) {
    regions.push_back(region);
}

std::vector<std::string> Map::getRegions() {
    return regions;
}

std::vector<Map> Map::getSubgraphs() {
    return subgraphs;
}

//TODO fix case where edge already exists
void Map::addEdge(Edge &e) {
    edges.push_back(e);
}

//TODO finish function to return Map with regions selected
Map Map::createFinalMap() {
    Map g = Map();
    //take selected regions and add them to final graph
//    for(every subgraph selected) {
//
//    }
    //add edges between regions selected
    return g;
}

//void Map::placeHouse(Vertex v, House h) {
//    v.setHouse(h);
//}
