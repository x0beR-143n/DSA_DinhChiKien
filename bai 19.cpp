#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, weight;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->weight = w;
    }
};

int find(vector<int> parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(vector<int> parent, vector<int> rank, int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);

    if (rank[x_root] < rank[y_root]) {
        parent[x_root] = y_root;
    }
    else if (rank[x_root] > rank[y_root]) {
        parent[y_root] = x_root;
    }
    else {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

void vyssotsky(int V, int E, const vector<Edge> edges) {
    vector<Edge> result;
    int i = 0, e = 0;

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });

    while (e < V - 1 && i < E) {
        int u = sortedEdges[i].u;
        int v = sortedEdges[i].v;
        int w = sortedEdges[i].weight;
        ++i;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y) {
            ++e;
            result.push_back(Edge(u, v, w));
            Union(parent, rank, x, y);
        }
    }
    for (Edge edge : result) {
        cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<Edge> edges;
    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    vyssotsky(numVertices, numEdges, edges);
    return 0;
}
