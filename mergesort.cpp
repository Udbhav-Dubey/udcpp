#include <bits/stdc++.h>
using namespace std;
void merge(vector <int>&vec,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector <int> L(n1),R(n2);
    for (int i=0;i<n1;i++){
        L[i]=vec[left+i];
    }
    for (int j=0;j<n2;j++){
        R[j]=vec[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            vec[k]=L[i];
            i++;
        }
        else {
        vec[k]=R[j];
        j++;
        }
        k++;
    }
    while(i<n1){
    vec[k]=L[i];
    i++;
    k++;
    }
    while(j<n2){
    vec[k]=R[j];
    j++;
    k++;
    }
}
void mergeSort(vector <int>&vec,int left,int right){
    if (left>=right){return;}
    int mid = left+(right-left)/2;
    mergeSort(vec,left,mid);
    mergeSort(vec,mid+1,right);
    merge(vec,left,mid,right);
}
void printVector(vector <int> &vec){
        for (auto it : vec){
            cout << it << " "; 
        }
        cout << endl;
    }
int main (){
    vector <int> vec;
    int x;
    while(cin>>x){
    vec.push_back(x);
    if (cin.peek()=='\n') break;
    }
    int n=vec.size();
    printVector(vec);
    mergeSort(vec,0,n-1);
    cout<< "sorted array is " << endl;
    printVector(vec);
    return 0;
}
