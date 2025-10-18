#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&vec,int low,int high){
    int pivot=vec[low];
    int j=high;
    for (int i=high;i>low;i--){
        if (arr[i]>pivot){
            swap(arr[i],arr[j--]);
        }
    }
        swap(arr[low],arr[k]);
        return j;
}
quicksort(vector<int> &vec,int low,int high){
    if (low<high){
        int idx=partition(arr,low,high);
        quicksort(vec,low,idx-1);
        quicksort(vec,idx+1,high);
    }
}
int main (){
    vector <int> vec;
    int x;
    while(cin>>x){
        vec.push_back(x);
        if(cin.peek=='\n') break;
    }
    quicksort(vec,0,vec.size()-1);
    for (auto it : vec){
        cout << it << " ";
    }
return 0;
}
