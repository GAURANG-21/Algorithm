#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]){
    vector<int> visited(v,0);
    queue<int> q;
    visited[0] =1 ;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node])
        if(!visited[it])
        {
            visited[it] = 1;
            q.push(it);
        }
    }
    return bfs;
}

 int main(){
    int n,m;
    printf("Enter number of nodes and edges\n");
    cin>>n>>m;
    vector<int> adj[n];
    for(int i =0; i<m;i++)
    {
        int u,v;
        printf("Enter two values between which the edge exists\n");
        cin>>u>>v;
        //u--->v
        adj[u-1].push_back(v-1);
        //v--->u
        adj[v-1].push_back(u-1);
    }
    vector<int> bfs = bfsOfGraph(n,adj);
    for(auto it: bfs)
    cout<<it<<endl;
    return 0;
 }