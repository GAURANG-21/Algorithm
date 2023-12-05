#include <iostream> 
using namespace std;

int main(){
    //n - number of nodes/vertex
    //m - number of edges
    int n, m;
    cin>>n,m;
    int adj[n+1][m+1];
    for(int i = 0;i<m;i++)
    {
        //The value of edges i.e. from where to where the edges go.
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}