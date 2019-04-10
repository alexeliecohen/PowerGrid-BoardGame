//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_MAP_H
#define COMP345TEAM21_MAP_H

#include "Vertex.h"

class Map {
public:
    int numVertex();
    int numEdges();
    std::vector<Vertex> getVertices();
    std::vector<Edge> getEdges();
    std::vector<std::string> getRegions();
    void addVertex(const Vertex &v);
    void addEdge(Vertex &u, Vertex &v, int cost);
    void addRegion(const std::string& region);
    static Vertex opposite(const Vertex& v, const Edge& e);
    Vertex findVertex(const std::string& s);
    Vertex* findVertexP(const std::string& s);
    bool BFS();
    int shortestPath(const std::string& src, const std::string& destination);
    std::vector<std::string> findingUnusedRegions(std::vector<std::string> regionsUsed);
    void createFinalMap(std::vector<std::string> &regionsUsed);
    bool checkAdjacentRegions(const std::string& r1, const std::string& r2);
    friend std::ostream& operator<<(std::ostream& os, Map& m);
    static bool canBuildHouse(Vertex city, int gamePhase);
    static Map* Instance();
protected:
    Map();
private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<std::string> regions;
    static Map* _instance;
};

#endif //COMP345TEAM21_MAP_H
