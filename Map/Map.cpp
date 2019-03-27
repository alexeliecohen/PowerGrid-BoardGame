//
// Created by Hubert on 2/9/2019.
//
//TODO add comments

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

Map::Map() {
    vertices = std::vector<Vertex>();
    edges = std::vector<Edge>();
    regions = std::vector<std::string>();
    subgraphs = std::vector<Map>();
}

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

std::vector<Edge> Map::getVertexEdges(Vertex v) {
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
            for(auto &e : getVertexEdges(u)) {
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

void Map::addEdge(Edge &e) {
    if(!(std::find(edges.begin(), edges.end(), e) != edges.end())) {
        edges.push_back(e);
    }
    else {
        std::cout << "Edge already exists";
    }
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

//TODO implement method
void Map::removeVertex(Vertex v) {
    auto i = std::find(vertices.begin(), vertices.end(), v);
    //vertices.erase(vertices.begin() + 0);
}

//TODO implement method
void Map::removeEdge(Edge e) {
    Vertex* endpoints = e.getEndpoints();
    std::vector<Edge> e1 = endpoints[0].getEdges();
    std::vector<Edge> e2 = endpoints[1].getEdges();
    auto i = std::find(edges.begin(), edges.end(), e);
    edges.pop_back();
}

static bool comparePair(const std::pair<int, std::string> p1, const std::pair<int, std::string> p2) {
    return p1.first < p2.first;
}

int Map::shortestPath(std::string src, std::string destination) {
    std::unordered_map<std::string, int> d;
    std::unordered_map<std::string, int> cloud;
    std::list<std::pair<int, std::string>> pq;
    std::unordered_map<std::string, std::pair<int, std::string>> pqTokens;
    for(Vertex v : vertices) {
        if(v.getName() == src) {
            d.insert(std::pair<std::string, int> (v.getName(), 0));
        }
        else {
            d.insert(std::pair<std::string, int> (v.getName(), INT_MAX));
        }
        pq.push_back(std::pair<int, std::string> (d.at(v.getName()), v.getName()));
        pqTokens.insert(std::pair<std::string, std::pair<int, std::string>> (v.getName(), std::pair<int, std::string> (d.at(v.getName()), v.getName())));
    }
    //while(!pq.empty()) {
        pq.sort(comparePair);
        std::pair p = pq.front();
        //std::cout << p.first << " " << p.second << "\n";
        pq.erase(pq.begin());
        Vertex u = findVertex(p.second);
        int key = p.first;
        cloud.insert(std::pair (u.getName(), key));
        pqTokens.erase(u.getName());
        for(const Edge &e : getVertexEdges(u)) {
            Vertex v = opposite(u, e);
            std::cout << v;
            pq.remove(std::pair(d.at(v.getName()), v.getName()));
            if(cloud.find(v.getName()) == cloud.end()) {
                int wgt = e.getCost();
                if(d.at(u.getName()) + wgt < d.at(v.getName())) {
                    d.insert(std::pair (v.getName(), d.at(u.getName()) + wgt));
                    std::pair p1(d.at(u.getName()) + wgt, v.getName());
                    std::cout << p1.first << " " << p1.second << "\n";
                    pq.push_back(p1);
                }
            }
        }
    //}
//    for(auto v : vertices) {
//        std::cout << v.getName() << " " << cloud.at(v.getName()) << "\n";
//    }
    //return cloud.at(destination);
    return 0;
}

//void Map::placeHouse(Vertex v, House h) {
//    v.setHouse(h);
//}
