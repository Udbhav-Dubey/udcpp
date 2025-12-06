#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int l=arr[high];
    int i=low-1;
    for (int j=i+1;j<=high;j++){
        if (arr[j]<=l){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quicksort(vector<int>&arr,int low,int high){
    if (low<high){
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
}}
int main (){
    return 0;  
}
