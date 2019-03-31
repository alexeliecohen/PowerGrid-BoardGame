//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_MAP_H
#define COMP345TEAM21_MAP_H

#include <vector>
#include <string>
#include "Vertex.h"

class Map {
public:
    Map();
    int numVertex();
    int numEdges();
    std::vector<Vertex> getVertices();
    std::vector<Edge> getEdges();
    std::vector<std::string> getRegions();
    void addVertex(const Vertex &v);
    void addEdge(Vertex &u, Vertex &v, int cost);
    void addEdge(Edge &e);
    void addRegion(const std::string& region);
    static Vertex opposite(const Vertex& v, const Edge& e);
    Vertex findVertex(const std::string& s);
    bool isVertex(const std::string& nameIn);
    bool BFS();
    int shortestPath(const std::string& src, const std::string& destination);
    void createFinalMap(std::vector<std::string> regionsUsed);
    friend std::ostream& operator<<(std::ostream& os, Map& m);
private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<std::string> regions;
};

#endif //COMP345TEAM21_MAP_H
