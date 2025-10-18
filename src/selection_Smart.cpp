#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int> arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
        if (cin.peek()=='\n') break;
    }
    cout << "before sorting : ";
    for (auto it : arr){
        cout << it << " ";
    }
    int n=vec.size();
    for(int i=0,j=n-1;i<j;i++,j--){
        int min=arr[i],max=arr[j];
        int min_i=i,max_i=i;
        for (int k=i+1;k<=j;k++){
            if (arr[k]>max){
                max=arr[k];
                max_i=k;
            }
            else if (arr[k]<min){
                min=arr[k];
                min_i=k;
            }
        }
        swap(arr[i],arr[min_i]);
        if (arr[min_i]==max){
            swap(arr[j],arr[min_i]);
        }
        else swap(arr[j],arr[max_i]);
    }
return 0;
}
