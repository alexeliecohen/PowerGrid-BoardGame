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
    std::vector<Map> getSubgraphs();
    std::vector<Edge>* getVertexEdges(Vertex v);
    void addVertex(Vertex v);
    void addEdge(Vertex &u, Vertex &v, int cost);
    void addEdge(Edge &e);
    void addRegion(std::string region);
    void removeEdge(Edge e);
    void removeVertex(Vertex v);
    Vertex opposite(Vertex v, Edge e);
    Vertex findVertex(std::string s);
    bool BFS();
    void createSubgraphs();
    Map createFinalMap();
    friend std::ostream& operator<<(std::ostream& os, Map& m);
//    void placeHouse(Vertex v, House h);
     bool isVertex(std::string nameIn);
private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<std::string> regions;
    std::vector<Map> subgraphs;
};

#endif //COMP345TEAM21_MAP_H
