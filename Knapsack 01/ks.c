#include <stdio.h>

int max(int a, int b)
{
    if (a>=b) return a;
    else return b;
}
int knapsack( int weights[], int value[], int n, int maxWeight, int ind, int w){
    if(ind == 0)
    if(weights[ind]<=w)
    return value[ind];
    else return 0;
    int not_take = 0 + knapsack(weights, value, n, maxWeight, ind-1, w);
    int take = -1;
    if(weights[ind]<=w)
    take = value[ind] + knapsack(weights, value, n, maxWeight, ind-1, w-weights[ind]);
    return max(not_take, take);
}
int main(){
        int n, maxWeight, i;
    printf("Enter value of n: ");
    scanf("%d",&n);
    int weight[n];
    int value[n];
    printf("Enter values of weights: \n");
    for(i=0;i<n;i++)
    scanf("%d",&weight[i]);
    printf("Enter values of profits: \n");
    for(i=0;i<n;i++)
    scanf("%d",&value[i]);
    printf("Enter values of bagWeight: \n");
    scanf("%d",&maxWeight);
    printf("%d",knapsack(weight, value, n, maxWeight, n-1, maxWeight));
}