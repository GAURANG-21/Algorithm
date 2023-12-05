#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &value ,int n, int maxWeight, int ind, int w, vector<vector<int>> &dp){
    if(ind == 0 )
    if(weights[0]<=w)
    return value[0];
    else
    return 0;
    if(dp[ind][w]!=-1)
    return dp[ind][w];
    int not_take = 0 + knapsack(weights, value, n, maxWeight, ind-1, w, dp);
    int 
    take = INT_MIN;
    if(weights[ind]<=w)
    take = value[ind]+knapsack(weights, value, n, maxWeight, ind-1, w-weights[ind], dp);
    return dp[ind][w]=max(not_take, take);
}
int main(){
    int n, maxWeight, i;
    cout<<"Enter value of n: ";
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    cout<<n<<endl;
    cout<<"Enter values of weights: "<<endl;;
    for(i=0;i<n;i++)
    cin>>weight[i];
    cout<<"Enter values of profits: "<<endl;
    for(i=0;i<n;i++)
    cin>>value[i];
    cout<<"Enter value of bag weight: ";
    cin>>maxWeight;
    vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
    cout<<knapsack(weight, value, n, maxWeight, n-1, maxWeight, dp);
}
