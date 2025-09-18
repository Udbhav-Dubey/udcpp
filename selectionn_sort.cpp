#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr){
    int n=arr.size();
    for (int i=0;i<n-1;i++){
        int min_idx=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
                swap(arr[i],arr[min_idx]);
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
    selectionSort(arr);
    cout << "\nSorted array: \n";
    printVector(arr);
return 0;
}
