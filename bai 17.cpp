#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);

    if (rank[x_root] < rank[y_root])
        parent[x_root] = y_root;
    else if (rank[x_root] > rank[y_root])
        parent[y_root] = x_root;
    else {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

void vyssotsky(int V, int E, vector<vector<int>>& edges) {
    vector<vector<int>> result;
    int i = 0, e = 0;

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    vector<vector<int>> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[2] < b[2];
         });

    while (e < V - 1 && i < E) {
        int u = sortedEdges[i][0];
        int v = sortedEdges[i][1];
        int w = sortedEdges[i][2];
        i++;
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y) {
            e++;
            result.push_back({u, v, w});
            Union(parent, rank, x, y);
        }
    }
    for (vector<int>& tmp : result) {
        cout << tmp[0] << " - " << tmp[1] << ": " << tmp[2] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3, 0));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }
    vyssotsky(n, m, edges);
    return 0;
}
