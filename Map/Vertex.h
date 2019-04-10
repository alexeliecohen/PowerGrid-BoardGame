//
// Created by Hubert on 2/9/2019.
//

#ifndef COMP345TEAM21_VERTEX_H
#define COMP345TEAM21_VERTEX_H

#include "Edge.h"
#include <string>
#include <vector>

class Edge;

class Vertex {
public:
    Vertex();
    Vertex(const std::string& name, const std::string& region);
    Vertex(const Vertex &v);
    int getCost();
    std::string getRegion() const;
    int getPlayerCount();
    std::string getName() const;
    void addEdge(const Edge& e);
    void setPlayer(const std::string& name);
    Vertex& operator=(const Vertex &v);
    bool operator==(const Vertex &v);
    friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
private:
    int cost[3]{};
    int playerCount = 0;
    std::string players[3];
    std::string name;
    std::string region;
    std::vector<Edge> edges;
};
#endif //COMP345TEAM21_VERTEX_H
