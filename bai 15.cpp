#include<bits/stdc++.h>
using namespace std;
void topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    queue<int> tmp;
    vector<int> result;
    for (vector<int>& neighbors : adj) {
        for (int neighbor : neighbors) {
            indegree[neighbor]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            tmp.push(i);
        }
    }
    while (!tmp.empty()) {
        int v = tmp.front();
        tmp.pop();
        result.push_back(v);

        for (int neighbor :adj[v]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                tmp.push(neighbor);
            }
        }
    }
    for (int v : result) {
        cout << v << " ";
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort(n, adj);
    return 0;
}
