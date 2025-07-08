#include <bits/stdc++.h>
using namespace std;
pair<int,int> dualPivotPartition(vector<int> &vec,int low,int high){
    if (vec[low]>vec[high]){
        swap(vec[low],vec[high]);
    }
    int pivot1=vec[low],pivot2=vec[high];
    int lt=low+1,gt=high-1;
    int i=lt;
    while(i<=gt){
        if (vec[i]<pivot1){
            swap(arr[i],arr[lt]);
            lt++;i++;   
        }
        else if (vec[i]>pivot2){
            swap(vec[i],vec[gt]);
            gt--;
        }
        else{i++:}
    }
swap(arr[low],arr[lt-1]);
swap(arr[high],arr[gt+1]);
return {lt-1,gt+1};
}
void dualPivotQuickSort(vector <int> &vec,int low,int high){
    if (low<high){
        pair<int,int> pivots=dualPivotPartition(vec,low,high);
        dualPivotQuickSort(vec,low,pivot.first-1);
        dualPivotQuickSort(vec,pivot.first+1,pivot.second-1);
        dualPivotQuickSort(vec,pivot.second+1,high);
    }
}
int main (){
    vector <int> vec;
    int x;
    while(cin>>x){
        vec.push_back(x);
        if(cin.peek()=='\n') break;
    }
    dualPivotQuickSort(vec,0,vec.size()-1);
    for (auto it : vec){
        cout << it << " ";
    }
return 0;
}
