#include <bits/stdc++.h>
using namespace std;
int minIndex(vector <int>&vec,int i ,int j){
    if (i==j) return i;
    int k=minIndex(vec,i+1,j);
    return (vec[i]<vec[k])?i:k;
}
void selectionsort(vector <int> &vec,int n,int index=0){
    if (index==n) return ;
    int k=minIndex(vec,index,n-1);
    if (k!=index){
        swap(vec[k],vec[index]);
    }
    selectionsort(vec,n,index+1);
}
int main (){
    vector<int> vec;
    int x;
    while(cin>>x){
        vec.push_back(x);
        if (cin.peek()=='\n') break;
    }
    selectionsort(vec,vec.size());
    for (auto it:vec){
        cout << it << " ";
    }
return 0;
}
