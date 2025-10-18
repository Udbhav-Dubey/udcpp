#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    vector<int>arr(n),prefix(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
        prefix[i]=arr[i]+((i>0)? prefix [i-1]:0);
    }
    int l=2,r=5;
    int sum=prefix[r]-((l>0)?prefix[l-1]:0);
}
