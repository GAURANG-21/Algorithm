#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

vector<int> dfsOfGraph(int node, vector<int> adj[], vector<int>&vis, vector<int>&ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it])
        dfsOfGraph(it, adj, vis, ls);
    }
    return ls;
}

int main(){
    int n, m;
    printf("Enter number of nodes and edges\n");
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        printf("Enter two values beween which the edge exists\n");
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<int> vis(n,0);
    vector<int> ls;
    vector<int> dfs = dfsOfGraph(0, adj, vis, ls);
    for(auto it: dfs)
    cout<<(it+1)<<endl;
    return 0;
}