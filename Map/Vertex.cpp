//
// Created by Hubert on 2/9/2019.
//

#include "Vertex.h"

Vertex::Vertex() {
    region = "none";
    name = "none";
    cost[0] = 10;
    cost[1] = 15;
    cost[2] = 20;
    playerCount = 0;
    for(int i = 0; i < players->size(); i++) {
        players[i] = "none";
    }
    edges = new std::vector<Edge>();
}

Vertex::Vertex(std::string name, std::string region) {
    this->region = region;
    this->name = name;
    cost[0] = 10;
    cost[1] = 15;
    cost[2] = 20;
    playerCount = 0;
    for(int i = 0; i < players->size(); i++) {
        players[i] = "none";
    }
    edges = new std::vector<Edge>();
}

Vertex::Vertex(const Vertex &v) {
    region = v.region;
    name = v.name;
    for(int i = 0; i < 3; i++) {
        cost[i] = v.cost[i];
    }
    playerCount = v.playerCount;
    for (int i = 0; i < v.players->size(); i++) {
        players[i] = v.players[i];
    }
    if(v.edges) {
        edges = new std::vector<Edge>();
        for(int i = 0; i < v.edges->size(); i++) {
            edges[i] = v.edges[i];
        }
    }
    else {
        edges = 0;
    }
}

std::vector<Edge>* Vertex::getEdges() {
    return this->edges;
}

int Vertex::getCost() {
    return cost[playerCount];
}

std::string Vertex::getRegion() {
    return region;
}

int Vertex::getPlayerCount() {
    return playerCount;
}

std::string Vertex::getPlayer(int i) {
    return players[i];
}

std::string Vertex::getName() {
    return name;
}

Vertex& Vertex::operator=(const Vertex &v) {
    if(this == &v) {
        return *this;
    }
    delete edges;
    playerCount = v.playerCount;
    name = v.name;
    region = v.region;
    for(int i = 0; i < 3; i++) {
        cost[i] = v.cost[i];
    }
    for(int i = 0; i < v.players->size(); i++) {
        players[i] = v.players[i];
    }
    if(v.edges) {
        edges = new std::vector<Edge>();
        for(int i = 0; i < v.edges->size(); i++) {
            edges[i] = v.edges[i];
        }
    }
    else {
        edges = 0;
    }
    return *this;
}