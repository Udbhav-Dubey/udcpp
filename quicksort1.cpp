#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &vec,int low,int high){
    int pivot=vec[high];
    int i=(low-1);
    for (int j=low;j<=high-1;j++){
        if (vec[j]<=pivot){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],vec[high]);
    return (i+1);
}
void quicksort(vector <int> &vec,int low,int high){
    if (low<high){
        int pi=partition(vec,low,high);
        quicksort(vec,low,pi-1);
        quicksort(vec,pi+1,high);
    }
}
int main (){
    cout << "enter the vector : ";
    vector <int> vec;
    int x;
    while(cin>>x){
        vec.push_back(x);
        if(cin.peek()=='\n') break;
    }
    quicksort(vec,0,vec.size()-1);
    for (auto it : vec){
        cout << it << " ";
    }
return 0;
}
