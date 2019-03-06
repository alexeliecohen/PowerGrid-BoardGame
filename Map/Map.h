//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_MAP_H
#define COMP345TEAM21_MAP_H

#include <vector>
#include "Vertex.h"

class Map {
public:
    Map();
    int numVertex();
    int numEdges();
    std::vector<Vertex>* getVertices();
    std::vector<Edge>* getEdges();
    int degree(Vertex v);
    std::vector<Edge>* getVertexEdges(Vertex v);
    void addVertex(Vertex v);
    void addEdge(Vertex &u, Vertex &v, int cost);
    Vertex opposite(Vertex v, Edge e);
    Vertex* findVertex(std::string s);
    bool BFS(Vertex &v);
    friend std::ostream& operator<<(std::ostream& os, Map& m);
private:
    std::vector<Vertex>* vertices;
    std::vector<Edge>* edges;
};

#endif //COMP345TEAM21_MAP_H
