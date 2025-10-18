#include <bits/stdc++.h>
using namespace std;
void shellSort(vector<int>&arr){
    int n=arr.size();
    for (int gap=n/2;gap>0;gap=gap/2){
        for (int i=gap;i<n;i++){
            int key=arr[i];
            int j=i;
        
        while(j>=gap&&arr[j-gap]>key){
            arr[j]=arr[j-gap];
            j-=gap;
        }
        arr[j]=key;
    }
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
    shellSort(arr);
    cout << "\nSorted array: \n";
    printVector(arr);
return 0;
}
