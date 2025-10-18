#include <bits/stdc++.h>
using namespace std;
void partition(vector <int>&arr){
    int n = arr.size();
    int pivot=arr[n-1];
    int i=-1;
    for (int j=0;j<n;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[n-1]);
}
int main (){
    cout << "enter the array : ";
    vector<int> arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    partition(arr);
    for (auto it : arr){
        cout << it << " ";
    }
return 0;
}
