#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class solution 
{
    public:

    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(v);
        for(int i = 0;i<v;i++)
        dist[i] = 1e9;

        dist[s] = 0;
        pq.push({0,s});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                 int edgeWeight = it[1];
                 int adjNode = it[0];
            if((dis + edgeWeight)< dist[adjNode])
            { 
             dist[adjNode] = dis+edgeWeight;
             pq.push({dist[adjNode], adjNode});
             }
            }
        }
         return dist;
    }
    
};

int main() {
    int v, e, s; // Number of vertices, edges, and source node
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

    cout << "Enter the source node: ";
    cin >> s;

    solution obj;
    vector<int> result = obj.dijkstra(v, adj, s);

    cout << "Shortest distances from the source node " << s << " are:\n";
    for (int i = 0; i < v; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }
    return 0;
}
