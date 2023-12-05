#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] =1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,st,adj);
    }
    st.push(node);
}
vector<int> ts(int v, vector<int> adj[]){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i =0;i<v;i++){
         if(!vis[i])
         dfs(i,vis,st, adj);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
        adj[u].push_back(v);
        //v--->u
        // adj[v-1].push_back(u-1);
    }
    vector<int> Tsort = ts(n,adj);
    for(auto it: Tsort)
    cout<<(it)<<endl;
    return 0;
 }