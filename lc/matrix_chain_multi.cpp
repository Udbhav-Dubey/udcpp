#include <bits/stdc++.h>
using namespace std;
int MinMulti(vector<int>&arr,int i,int j,vector<vector<int>>&memo){
    if (i+1==j){
        return 0;
    }
    if (memo[i][j]!=-1){
        return memo[i][j];
    }
    int res=INT_MAX;
    for (int k=i+1;k<j;k++){
        int curr=MinMulti(arr,i,k,memo)+MinMulti(arr,k+1,j,memo)+arr[i]*arr[k]*arr[j];
        res=min(curr,res);
    }
    memo[i][j]=res;
    return res;
}
int Matrix_multi(vector<int>&arr){
    int n=arr.size();
    vector<vector<int>>memo(n,vector<int>(n,-1));
    return MinMulti(arr,0,n-1,memo);
}
int main(){
    vector<int>arr={2,1,3,4};
    cout << Matrix_multi(arr);
    return 0;
}
