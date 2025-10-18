#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector <int>arr1(n1),arr2(n2);
    for (int i=0;i<n1;i++){
        arr1[i]=arr[left+i];
    }
    for (int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=left;
    while (i<n1 &&  j <n2 ){
        if (arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else {
        arr[k]=arr2[j];
        j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr[j];
        j++;
        k++:
    }
}
void mergeSort(vector <int>&arr){
    int n=arr.size();
    for (int currentsize=1,currentsize<=n-1;currentSize=2*currentsize){
        for (int leftStart=0;leftStart<n-1;leftStart+=2*currentsize){
            int mid =min(leftStart+currentsize-1,n-1);
            int rightEnd=min(leftStart+2*currentsize-1,n-1);
            merge(arr,leftStart,mid,RightEnd);
        }
    }
}
int main (){
    vector<int> arr={4,1,3,9,7};
    mergeSort(arr);
    for (auto val : arr){
        cout << val << " ";
    }
    return 0;
}
