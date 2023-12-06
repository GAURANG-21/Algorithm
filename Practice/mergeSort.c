#include <stdio.h>
#include <stdlib.h>

int divisionCount = 0;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l +1;
    int n2 = r-m;

    //Formation of arrays
    int L[n1], R[n2];
    for(int i = 0;i<n1;i++)
    L[i] = arr[l+i];
    for(int j =0;j<n2;j++)
    R[j]= arr[j+m+1];

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        arr[k++] = L[i++];
        else
        arr[k++]=R[j++];
    }

    while(i<n1)
    arr[k++] = L[i++];

    while(j<n2)
    arr[k++] = R[j++];
    
}

void printArray(int arr[], int n){
    for(int i =0;i<n;i++)
    printf("%d \t", arr[i]);
    printf("\n");
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        divisionCount++;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[]= {19,32,52,21,32,312,23,31};
    int left = 1;
    int right = 8;
    printArray(arr, 8);
    mergeSort(arr, left, right);
    printArray(arr, 8);
}