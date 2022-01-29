//
// Created by nmls1 on 27/01/2022.
//

#ifndef REDEDEAUTOCARROS_GRAPH_H
#define REDEDEAUTOCARROS_GRAPH_H

#define INF (INT_MAX/2)

#include <string>
#include <list>
#include <vector>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        double weight; // An integer weight
        string line; //
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        double dist;
        int pred;
        bool visited;
        string name;
        string zone;
        int latitude;
        int longitude;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    void dijkstra(int s);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph();
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, double weight = 1.0);

    void bfs(int v);
    void bfsDist(int v);

    int distance(int a, int b);

    // ----- Functions to implement in this class -----
    double dijkstra_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);
};


#endif //REDEDEAUTOCARROS_GRAPH_H
