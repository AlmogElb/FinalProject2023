//
// Created by Almog on 20/04/2023.
//

#include "Actions.h"
#include <cassert>
#include <unordered_map>

vector<vector<int>> Actions::partition(int n, int g) {
    vector<vector<int>> res;
    vector<int> partition;
    find_partitions(n, g, partition, res);
   // print_partition(res);
    return res;
}

void Actions::find_partitions(int n, int g, vector<int> &partition, vector<vector<int>> &all_partitions) {

    if (n == 0) {
        all_partitions.push_back(partition);
        return;
    }

    if(g % 2 != 0){ // move to partition
        g++;
    }

    for (int i = g; i <= n; i += 2) {
        vector<int> new_partition = partition;
        new_partition.push_back(i);
        find_partitions(n-i, i, new_partition,all_partitions);
    }
}

void Actions::print_partitions(vector<vector<int>> all_partitions) {
    for (vector<int> partition : all_partitions) {
        cout << "[";
        for (int i : partition) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
}

void Actions::print_partition(vector<int> partition) {
    cout << "[";
    for (int i : partition) {
        cout << i << ",";
    }
    cout << "] " ;
}

bool Actions::searchForGraph(const vector<int>& part, int n, int g) {
    Graph* G = createCircleGraph(part, n);
    vector<int> partLeader(n);
    // initialize partLeader vector
    int c = 0, leader = 0;
    for(int i=0; i<n; i++){
        partLeader[i] = leader;
        if(i == leader + part[c] -1)
            leader += part[c++];
    }
    // create possible u vertices to start
    vector<int> possibleU;
    for (int u=0; u<=part[0]/2; u+=2){
        if (u >= g-1){
            possibleU.push_back(u);
        }
    }
    int sum = part[0];
    for (int j=1; j<part.size(); j++){
        if(j==1 || part[j] != part[j-1]){
            possibleU.push_back(sum);
        }
        sum+=part[j];
    }
    // the first loop
    int v = 0;
    bool res = false;
    for (int u: possibleU ){
        G->addEdge(v,u);
        res = helper_searchForGraph(G, g, part, partLeader);
        if (res) break;
        G->deleteEdge(v,u);
    }
    delete G;
    return res;
}

int Actions::find_first_unsatisfied(Graph *G) {
    for(int v=0; v<G->getSize(); v+=2) //only even vertex
        if(G->getDegree(v)==2) return v;
    return -1;
}

bool Actions::helper_searchForGraph(Graph* G, int g, const vector<int>& part, const vector<int>& partLeader){
    int v = find_first_unsatisfied(G);
    if (v<0) return true;
    assert(G->getDegree(v)==2);
    vector<int> dist = G->dijkstra(v);
    for(int u=0; u<dist.size(); u+=2){
        if (G->getDegree(u)!=2)
            continue;
        if (dist[u]>=g-1 || (dist[u] == -1 && u == partLeader[u])){
            G->addEdge(v,u);
            if(helper_searchForGraph(G, g, part, partLeader)){
                return true;
            }
            G->deleteEdge(v,u);
        }
    }
    return false;
}

Graph *Actions::createCircleGraph(const vector<int> &partition, int n) {
// Constructs a graph consisting of circles, according to the partition.
    Graph* G = new Graph(n);
    int k=0; //sum of the prev vertexes
    for(int i=0; i<partition.size(); i++){
        int j;
        for(j=0; j<partition[i]-1;j++){
            G->addEdge(k+j,k+j+1);
        }
        G->addEdge(k+j,k);
        k+= j+1;
    }
    return G;
}
