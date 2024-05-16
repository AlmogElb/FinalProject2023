//
// Created by Almog on 20/04/2023.
//

#ifndef BIGPROJECT_ACTIONS_H
#define BIGPROJECT_ACTIONS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"
using namespace std;

class Actions {
private:
    void find_partitions(int n, int g, vector<int> &partition, vector<vector<int>> &all_partitions);
    int find_first_unsatisfied(Graph *G);
    bool helper_searchForGraph(Graph* G, int g, const vector<int>& part, const vector<int>& partLeader);
    int indexOfCheckPart(const int u, const vector<int>& part);

public:
    Actions(){};
    vector<vector<int>> partition(int n, int g);
    bool searchForGraph(const vector<int>& part, int n, int g);
    void print_partitions(vector<vector<int>> all_partitions); // to delete
    void print_partition(vector<int> partition);
    Graph* createCircleGraph(const vector<int> &partition, int n);
};

#endif //BIGPROJECT_ACTIONS_H
