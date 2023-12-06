#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Kruskal {
public:
    vector<pair<int, pair<int, int>>> spanningTree(int v, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < v; i++)
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        DisjointSet ds(v);
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<int, int>>> mstEdges;  // To store MST edges
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUpar(u) != ds.findUpar(v)) {
                mstWt += wt;
                mstEdges.push_back({wt, {u, v}});
                ds.unionByRank(u, v);
            }
        }
        return mstEdges;
    }
};

int main() {
    int v, e; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adj[v]; // Adjacency list

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges and their weights (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        adj[source].push_back({destination, weight});
        adj[destination].push_back({source, weight}); // Assuming an undirected graph
    }

    Kruskal k;
    vector<pair<int, pair<int, int>>> mstEdges = k.spanningTree(v, adj);

    cout << "Minimum Spanning Tree Edges and Weights:\n";
    for (auto edge : mstEdges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << "Edge: " << u << " - " << v << ", Weight: " << wt << endl;
    }

    return 0;
}
