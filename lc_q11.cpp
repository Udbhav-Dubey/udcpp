#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j=height.size()-1;
        int maxarea=0;
        bool b=1;
        while(i<j){
            int distance=j-i;
            int area=min(height[i],height[j]);
            area=area*distance;
           maxarea=max(area,maxarea);
            cout << "i is " << i <<"and j is " << j<<endl;
            cout << "distance is " << distance << endl;
            cout << "area is " << area<<endl;
            cout << "max area is "<<maxarea<<endl;
            cout << "b is "<< b<<endl;
            if ((min(height[i+1],height[j]))*distance-1 > area){i++;}
            else j--;
        }
        return maxarea;
    }
};
int main(){
    int x;
    vector<int> nums;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    cout <<sol.maxArea(nums);
return 0;
}

