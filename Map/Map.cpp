//
// Created by Hubert on 2/9/2019.
//

#include "Map.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

/**
 * Helper function for the shortest path algorithm,
 * Compares two standard library pairs based on the first value
 * @param p1 a standard library pair
 * @param p2 a second standard library pair
 * @return if the first pair is smaller than the second
 */
static bool comparePair(const std::pair<int, std::string> &p1, const std::pair<int, std::string> &p2) {
    return p1.first < p2.first;
}

/**
 * Default constructor for the map
 */
Map::Map() {
    vertices = std::vector<Vertex>();
    edges = std::vector<Edge>();
    regions = std::vector<std::string>();
}

/**
 * calculates the number of vertices in the map
 * @return the number of vertices
 */
int Map::numVertex() {
    return vertices.size();
}

/**
 * calculates the number of edges in the map
 * @return the number of edges
 */
int Map::numEdges() {
    return edges.size();
}

/**
 * Getter for the set of vertices for the map
 * @return a vector of vertices
 */
std::vector<Vertex> Map::getVertices() {
    return vertices;
}

/**
 * Getter fot the set of edges for the map
 * @return a vector of edges
 */
std::vector<Edge> Map::getEdges() {
    return edges;
}

/**
 * Getter for the set of region names of the map
 * @return a vector with the region names
 */
std::vector<std::string> Map::getRegions() {
    return regions;
}

/**
 * Method to add a new vertex to the map
 * @param v the vertex to be added
 */
void Map::addVertex(const Vertex &v) {
    if(!(std::find(vertices.begin(), vertices.end(), v) != vertices.end())) {
        vertices.push_back(v);
    }
    else {
        std::cout << "Vertex already exists";
    }
}

/**
 * Method to add a new edge to the map
 * @param u an endpoint
 * @param v the other endpoint
 * @param cost the weight of the edge
 */
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

/**
 * Adds an edge to the graph
 * @param e an edge
 */
void Map::addEdge(Edge &e) {
    if(!(std::find(edges.begin(), edges.end(), e) != edges.end())) {
        edges.push_back(e);
    }
    else {
        std::cout << "Edge already exists";
    }
}

/**
 * Adds a new region name to the graph
 * @param region a region name
 */
void Map::addRegion(const std::string &region) {
    regions.push_back(region);
}

/**
 * Method to find the vertex opposite the given vertex, through the given edge
 * @param v the starting vertex
 * @param e the edge to go through
 * @return the vertex opposite the edge
 */
Vertex Map::opposite(const Vertex& v, const Edge &e) {
    Vertex* endpoints = e.getEndpoints();
    if(endpoints[0] == v) {
        return endpoints[1];
    }
    else {
        return endpoints[0];
    }
}

/**
 * Method to find a specified vertex in the map
 * @param s the name of the vertex
 * @return the vertex with the specified name
 */
Vertex Map::findVertex(const std::string &s) {
    for (const auto &v : vertices) {
        if(v.getName() == s ) {
            return v;
        }
    }
    std::cout << "Vertex does not belong to the map. Please enter a valid vertex";
    exit(0);
}

bool Map::isVertex(const std::string &nameIn){
	bool returnValue = false;
	for (auto &vertex : vertices)
		if ( vertex.getName() == nameIn)
			returnValue = true;
	return returnValue;
}//close isVertex

/**
 * Method to check if the map is connected, implemented using breadth-first search
 * @return if the graph is connected
 */
bool Map::BFS() {
    auto level = std::vector<Vertex>();
    auto known = std::vector<Vertex>();
    level.push_back(vertices.at(0));
    known.push_back(vertices.at(0));
    while(!level.empty()) {
        auto nextLevel = std::vector<Vertex>();
        for(auto &u : level) {
            for(auto &e : edges) {
                if(e.getEndpoints()[0] == u || e.getEndpoints()[1] == u) {
                    Vertex v = opposite(u, e);
                    if (!(std::find(known.begin(), known.end(), v) != known.end())) {
                        known.push_back(v);
                        nextLevel.push_back(v);
                    }
                }
            }
        }
        level = nextLevel;
    }
    return known.size() == numVertex();
}

/**
 * Method to calculate the shortest path between two vertices in the map
 * @param src the starting vertex
 * @param destination the ending vertex
 * @return the shortest path between the two vertices
 */
int Map::shortestPath(const std::string &src, const std::string &destination) {
    std::unordered_map<std::string, int> d;
    std::unordered_map<std::string, int> cloud;
    std::list<std::pair<int, std::string>> pq;
    std::unordered_map<std::string, std::pair<int, std::string>> pqTokens;
    for(const Vertex &v : vertices) {
        if(v.getName() == src) {
            d.insert(std::pair<std::string, int> (v.getName(), 0));
        }
        else {
            d.insert(std::pair<std::string, int> (v.getName(), INT_MAX));
        }
        pq.emplace_back(d.at(v.getName()), v.getName());
        pqTokens.insert(std::pair<std::string, std::pair<int, std::string>> (v.getName(), std::pair<int, std::string> (d.at(v.getName()), v.getName())));
    }
    while(!pq.empty()) {
        pq.sort(comparePair);
        std::pair p = pq.front();
        pq.erase(pq.begin());
        Vertex u = findVertex(p.second);
        int key = p.first;
        std::pair p2(u.getName(), key);
        cloud.insert(p2);
        pqTokens.erase(u.getName());
        for(auto &e : edges) {
            if(e.getEndpoints()[0] == u || e.getEndpoints()[1] == u) {
                Vertex v = opposite(u, e);
                if(cloud.find(v.getName()) == cloud.end()) {
                    int wgt = e.getCost();
                    if(d.at(u.getName()) + wgt < d.at(v.getName())) {
                        d.erase(v.getName());
                        d.insert(std::pair (v.getName(), d.at(u.getName()) + wgt));
                        pq.remove(std::pair(d.at(v.getName()), v.getName()));
                        std::pair p1(d.at(u.getName()) + wgt, v.getName());
                        pq.push_back(p1);
                    }
                }
            }
        }
    }
    if(cloud.find(destination) == cloud.end()) {
        return -1;
    }
    else {
        return cloud.at(destination);
    }
}

/**
 * Method to create the final map to be used in the game
 * @return a map
 */
void Map::createFinalMap(std::vector<std::string> regionsUsed) {
    for(std::string s1 : regions) {
        std::cout << s1 << "\n";
    }
    for(const std::string &s : regions) {
        std::cout << s << "\n";
        std::cout << "Position in regions used " << std::find(regionsUsed.begin(), regionsUsed.end(), s) - regionsUsed.begin() << "\n";
        if(!(std::find(regionsUsed.begin(), regionsUsed.end(), s) != regionsUsed.end())) {
            auto position = std::find(regions.begin(), regions.end(), s);
            std::cout << "Position in regions " << position - regions.begin() << "\n";
            if (position != regions.end()) {
                std::cout << regions.at(position - regions.begin()) << "\n";
                regions.erase(position);
            }
        }
    }
}

/**
 * Operator overload for the output stream
 * @param os an output stream
 * @param m a map object
 * @return a stream to output the contents of the map
 */
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
