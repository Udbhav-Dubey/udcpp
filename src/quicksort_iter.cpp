#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &vec,int low,int high){
    int pivot=vec[high];
    int i=low-1;
    for (int j=low;j<=high;j++){
        if (vec[j]<=pivot){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],vec[high]);
    return i+1;
}
void quicksort(vector <int> &vec,int low,int high){
    int stack[high-low+1];
    int top=-1;
    stack[++top]=low;
    stack[++top]=high;
    while(top>=0){
        high=stack[top--];
        low=stack[top--];
        int p=partition(vec,low,high);
        if (p-1>low){
            stack[++top]=low;
            stack[++top]=p-1;
        }
        if (p+1<high){
            stack[++top]=p+1;
            stack[++top]=high;
        }
    }
}
int main (){
    vector <int> vec;
    int x;
    while(cin>>x){
    vec.push_back(x);
    if(cin.peek()=='\n') break;
    }
    quicksort(vec,0,vec.size()-1);
    for (auto it:vec){
        cout << it << " ";
    }
    return 0;
}
