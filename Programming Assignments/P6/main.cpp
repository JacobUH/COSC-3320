// 4f343291-5ce3-4d65-9ead-4c9e2ab4d269

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void explore (vector <vector<int>> &graph, int r, int c, int size){
    if (r < 0 || r >= size || c < 0 || c >= size)
        return;

    if (graph[r][c] == 0)
        return;

    graph[r][c] = 0;
    explore(graph, r-1, c, size);
    explore(graph, r, c-1, size);
    explore(graph, r, c+1, size);
    explore(graph, r+1, c, size);
}

int islandCount(vector <vector<int>> graph, int size){
    int count = 0;
    for (int r = 0; r < size; r++){
        for (int c = 0; c < size; c++){
            if (graph[r][c] == 1){
                explore(graph, r, c, size);
                count++;
            }
        }
    }
    return count;
}


int main(){
    int n = 0;
    cin >> n;

    vector <vector<int>> graph(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> graph[r][c];
        }
    }
    cout << islandCount(graph, n);
    return 0;
}