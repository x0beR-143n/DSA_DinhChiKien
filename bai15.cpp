#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int u = 0; u < V; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    for (int u = 0; u < V; u++) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {2, 7},     // Đỉnh 0 có cạnh đi đến đỉnh 7 và 2
        {2, 7},     // Đỉnh 1 có cạnh đi đến đỉnh 2 và 7
        {3, 4, 5},  // Đỉnh 2 có cạnh đi đến đỉnh 3,4 và 5
        {},         // Đỉnh 3 không có cạnh đi ra
        {5},        // Đỉnh 4 có cạnh đi đến đỉnh 5
        {},         // Đỉnh 5 không có cạnh đi ra
        {3},        // Đinh 6 có cạnh đi đến đỉnh 3
        {4}         // Đinh 7 có cạnh đi đến đỉnh 4
    };
    topologicalSort(graph);
    return 0;
}
/**
8 10
1 2
0 2
0 7
1 7
6 3
2 5
2 4
2 3
7 4
4 5
*/
