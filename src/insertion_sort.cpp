#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&arr){
    int n=arr.size();
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
    
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
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
    insertionSort(arr);
    cout << "\nSorted array: \n";
    printVector(arr);
return 0;
}
