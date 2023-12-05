#include <stdio.h>


int tsp(int n, int dist[][n], int mask, int pos, int visited_all)
{
    // for(int i =0; i<n;i++)
    //     for(int j = 0; j<n; j++)
    //     printf("%d", dist[i][j]);
    if ( mask == visited_all)
    return dist[pos][0];
    int ans = __INT32_MAX__;
    for(int city = 0 ; city<n;city++)
    if((mask&(1<<city))==0)
    {
        int newAns = dist[pos][city] + tsp(n,dist,(mask|(1<<city)),city,visited_all);
        if(ans>=newAns)
        ans = newAns;
    }
    return ans;
}
int main(){
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    int visited_all = (1<<n)-1;
    char city[] = {'A','B','C','D','E'};
    int dist[n][n];
    for(int i =0; i<n;i++)
        for(int j = 0; j<n; j++)
        { printf("\nEnter distance between %c and %c: ",city[i],city[j]);
         scanf("%d", &dist[i][j]);}
    printf("%d",tsp(n,dist, 1, 0 ,visited_all));
    return 0;
}