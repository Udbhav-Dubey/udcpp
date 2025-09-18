#include <bits/stdc++.h>
using namespace std;
    int partition(vector<int>&vec,int low,int high){
        int pivot=vec[high];
        int i=low-1;
        for (int j=low;j<=high;j++){
            if (vec[j]<=pivot){
                i++;
                swap(vec[i],vec[j]);
            }
        }
        swap(vec[i+1],vec[high]);
        return i+1;
    }
void quicksort(vector<int>&vec,int low,int high){
    if (low<high){
        int pi=partition(vec,low,high);
        quicksort(vec,low,pi-1);
        quicksort(vec,pi+1,high);
    }
}
void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << " " << num;
}
int main (){
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "array is :" << endl;
    printVector(arr);
    quicksort(arr,0,arr.size());
    cout << "\nSorted array: \n";
    printVector(arr);
return 0;
}
