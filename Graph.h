//
// Created by Almog on 18/03/2023.
//
#ifndef BIGPROJECT_GRAPH_H
#define BIGPROJECT_GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adjList;

public:
    Graph(int n);
    ~Graph();
    void addEdge(int i, int j);
    void deleteEdge(int i, int j);
    int getDegree(int i);
    void print() const;
    vector<int> dijkstra(int start) const;
    int getSize() const;
};


#endif //BIGPROJECT_GRAPH_H
