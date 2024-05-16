#include <iostream>
#include <vector>
#include <ctime>
#include "Graph.h"
#include "Actions.h"
using namespace std;

int main() {
    Actions a;
    int n = 48;
    int g = 11;
    double cnt = 0;
    vector<vector<int>> part = a.partition(n,g);
    for(int i=0; i<part.size(); i++) {
        clock_t start_t = clock();
        a.print_partition(part[i]);
        cout << "result: ";
        cout << a.searchForGraph(part[i], n, g) << " , Time: ";
        cout << double(clock()-start_t)/CLOCKS_PER_SEC << " sec" << endl;
        cnt += double(clock()-start_t)/CLOCKS_PER_SEC;
    }
    cout << "TOTAL TIME: " << cnt << endl;
    return 0;
}

