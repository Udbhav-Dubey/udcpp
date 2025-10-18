#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int>&arr){
    int n=arr.size();
    int k=*max_element(arr.begin(),arr.end());
    vector<int>count(k+1,0);
    for (int num:arr){
        count[num]++;
    }
    for (int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    vector<int>output(n);
    for (int i=n-1;i>=0;i--){
        int num=arr[i];
        output[count[num]-1]=num;
        count[num]--;
    }
    arr=output;
}
void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << " " << num;
}
int main (){
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "array is :" << endl;
    printVector(arr);
    countingSort(arr);
    cout << "\nSorted array: \n";
    printVector(arr);
return 0;
}
