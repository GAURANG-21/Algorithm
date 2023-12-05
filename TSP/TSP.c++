#include <iostream> 
using namespace std;

#define INT_MAX 999999

int n =4;
//Adj Matrix which defines the graph
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

//If all citits have been visited
int VISITED_ALL = (1<<n)-1;
//mask denotes which cities have been visited
//pos is the where we start
int tsp(int mask, int pos){
    if(mask == VISITED_ALL)
    return dist[pos][0];
    //Try going to unvisited cities
    int ans = INT_MAX;
        for ( int city = 0; city < n;city++)
        {
              if((mask&(1<<city))==0)
              {
                int newAns = dist[pos][city] +tsp(mask|(1<<city),city);
                ans = min(ans, newAns);
              }
        }
        return ans;
}
int main(){
    cout<<tsp(1,0)<<endl;
}


 
#include <iostream>
using namespace std;

// #define INT_MAX 999999;

int n =4;
//Adj Matrix which defines the graph
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};


// //MEMOIZATION

// #include <iostream> 
// using namespace std;

// #define INT_MAX 999999

// int n =4;
// //Adj Matrix which defines the graph
// int dist[10][10]={
//     {0,20,42,25},
//     {20,0,30,34},
//     {42,30,0,10},
//     {25,34,10,0}
// };
// //If all citits have been visited
// int dp[16][4];
// int VISITED_ALL = (1<<n)-1;
// //mask denotes which cities have been visited
// //pos is the where we start
// int tsp(int mask, int pos){
//     if(mask == VISITED_ALL)
//     return dist[pos][0];
//     if(dp[mask][pos]!=-1)
//     return dp[mask][pos];
//     //Try going to unvisited cities
//     int ans = INT_MAX;
//         for ( int city = 0;city<n;city++)
//         {
//               if((mask&(1<<city))==0)
//               {
//                 int newAns = dist[pos][city] +tsp(mask|(1<<city),city);
//                 ans = min(ans, newAns);
//               }
//         }
//         return dp[mask][pos] = ans;
// }
// int main(){
//     for(int i = 0;i<(1<<n);i++)
//     for(int j = 0;j<n;j++)
//     dp[i][j] = -1;
//     cout<<VISITED_ALL;
//     cout<<tsp(1,0)<<endl;
// }