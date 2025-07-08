#include <bits/stdc++.h>
using namespace std;
int genrateRandomPivot(int low,int high){
    return low+rand() % (high-low+1);
}

void quicksort(vector <int> &vec,int low,int high){
    if (low<high){
        int pivotindex=genrateRandomPivot(low,high);
        int pivotValue=vec[pivotindex];
        swap(vec[pivotindex],vec[high]]);
        int i=low-1;
        for (int j=low;j<high;j++){
            if (vec[j]<pivotValue){
                i++;
                swap(vec[i],vec[j]);
            }
        }
        swap(vec[i+1],vec[high]);
        quicksort(vec,low,i);
        quicksort(vec,i+2,high);
    }
}
int main (){
    vector <int> vec;
    srand(time(NULL));
    int x;
    while(cin>>x){
    vec.push_back(x);
    if (cin.peek()=='\n') break;
    }
    quicksort(vec,0,vec.size()-1);
    for (auto it : vec){
        cout << it << " ";
    }
return 0;
}
