//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_VERTEX_H
#define COMP345TEAM21_VERTEX_H

#include <vector>
#include <string>
#include "Edge.h"

class Edge;

class Vertex {
public:
    Vertex();
    Vertex(const std::string name, const std::string region);
    Vertex(const Vertex &v);
    std::vector<Edge> getEdges();
    int getCost();
    std::string getRegion() const;
    int getPlayerCount();
    std::string getPlayer(const int i);
    std::string getName() const;
    void addEdge(Edge e);
    void setPlayer(std::string name);
    Vertex& operator=(const Vertex &v);
    bool operator==(const Vertex &v);
    friend std::ostream& operator<<(std::ostream& os, const Vertex v);
private:
    int cost[3];
    int playerCount = 0;
    std::string players[3];
    std::string name;
    std::string region;
    std::vector<Edge> edges;
};
#endif //COMP345TEAM21_VERTEX_H
