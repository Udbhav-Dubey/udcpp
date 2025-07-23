#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    int ans=0;
    for (auto it : nums){
        ans^=it;
    }
    cout << "your answer is : " << ans << endl;
return 0;
}
