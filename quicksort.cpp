#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &arr,int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for (int j=low;j<=high;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quicksort(vector <int> &arr,int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
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
    quicksort(arr,0,arr.size()-1);
    for (auto it : arr){
        cout << it << " ";
    }
return 0;
}
