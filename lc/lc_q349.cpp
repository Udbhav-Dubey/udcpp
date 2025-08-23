#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        unordered_set<int> ans;   
        for (int num : nums2){
            if (s.count(num)) ans.insert(num);
        }
        return  vector <int>(ans.begin(),ans.end());
    }
};
int main (){
    cout << "please enter the vectors\nvector 1: ";
    vector <int> nums1 ;
    int x;
    while (cin >> x){
        nums1.push_back(x);
        if (cin.peek()=='\n') break;
    }
    vector <int> nums2 ;
    int y;
    while (cin >> y){
        nums2.push_back(y);
        if (cin.peek()=='\n') break;
    }  
    Solution sol;
     vector<int> result = sol.intersection(nums1, nums2); 
    cout << "Intersection: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}
