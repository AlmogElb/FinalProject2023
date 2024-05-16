//
// Created by Almog on 18/03/2023.
//

#include "Graph.h"
#include <queue>

Graph::Graph(int n) {
    this->n = n;
    adjList = vector<vector<int>>(n);
}

Graph::~Graph() {}


void Graph::addEdge(int i, int j) {
    this->adjList[i].push_back(j);
    this->adjList[j].push_back(i);
}

void Graph::deleteEdge(int i, int j) {
    adjList[i].erase(remove(adjList[i].begin(), adjList[i].end(), j), adjList[i].end());
    adjList[j].erase(remove(adjList[j].begin(), adjList[j].end(), i), adjList[j].end());
}

void Graph::print() const {
    for (int u = 0; u < adjList.size(); ++u) {
        cout << u << ": ";
        for (auto p : adjList[u]) {
            cout << "(" << u << ", " << p << ") ";
        }
        cout << endl;
    }
}

vector<int> Graph::dijkstra(int start) const {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Priority queue to store the vertices and their distances
    vector<int> dist(n, -1);  // Initialize all distances to -1
    dist[start] = 0;  // Set the starting vertex's distance to 0
    pq.push({0, start});  // Push the starting vertex onto the priority queue

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the smallest distance
        pq.pop();

        for (auto v : adjList[u]) {  // Visit all adjacent vertices
            if (dist[v] == -1) {  // If the distance to v hasn't been calculated yet
                dist[v] = dist[u] + 1;  // Update the distance to v
                pq.push({dist[v], v});  // Push v onto the priority queue with its updated distance
            }
        }
    }
    return dist;  // Return the vector of distances from the starting vertex
}


int Graph::getDegree(int i) {
    return adjList[i].size();
}

int Graph::getSize() const {
    return n;
}
