#include <bits/stdc++.h>
using namespace std;
void partition(vector <int>&arr){
    int pivot=arr[0];
    int i=-1
    j=arr.size();
    while(1){
        do{i++}
        while(arr[i]<pivot);
        do{j--}
        while(arr[j]>pivot);
        if(i>j)break;
        swap(arr[i],arr[j]);
    }
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
