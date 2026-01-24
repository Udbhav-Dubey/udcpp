#include <bits/stdc++.h>
using namespace std;

void printin(vector<int>&arr){
    for (int a : arr){
        cout << a << " ";
    }
    cout << "\n";
}
void merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right){
    int k=left;
    int i=left;
    int j=mid+1;
    while(i<=mid&&j<=right){
        if (arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for (int u=left;u<=right;u++){
        arr[u]=temp[u];
    }
}
void mergesort(vector<int>&arr,vector<int>&temp,int left,int right){
    if (left>=right){
        return;
    }
    int mid=left+(right-left)/2;
    mergesort(arr,temp,left,mid);
    mergesort(arr,temp,mid+1,right);
    merge(arr,temp,left,mid,right);
}
int main (){
    int x;
    cout << "enter values by space and enter to stop feeding array\n";
    vector<int>arr;
    while(cin>>x){
        arr.push_back(x);
        if(cin.peek()=='\n'){break;}
    }
    cout << "original array is : ";
    printin(arr);
    vector<int>temp(arr.size());
    mergesort(arr,temp,0,arr.size()-1);
    cout << "sorted : " ;
    printin(arr);
    return 0;
}

