#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	if (nums.empty()) return 0;
        set <int> s={nums.begin(),nums.end()};
        int count=1;
        int max=1;
        auto prev=s.begin();
        auto it=next(s.begin());
        while (it!=s.end()){
            if (*it==*prev+1){
                count++;
            }else count=1;
            if (count>max){
                max=count;
            }
            prev=it;
            ++it;
        }
        return max;
    }
};
int main (){
    cout << "please enter the vector\n";
    vector <int>vec;
    int x;
    while (cin>>x){
        vec.push_back(x);
        if (cin.peek()=='\n')break;
    }
    Solution sol;
    cout << "\nthe output is " << sol.longestConsecutive(vec);
return 0;
}
