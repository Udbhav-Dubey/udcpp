#include <bits/stdc++.h>
using namespace std;
class Solution{
    public :
        int mySqrt(int x){
            int end=x;
            int start=1;
            while (end>start){
                int mid = start + (end-start)/2;
                if ((mid*mid)==x || (mid*mid)<x && (mid+1)*(mid+1)>x){return mid;}
                if (mid*mid>x){
                    end=mid;
                }
                if (mid*mid<x){start=mid;}
            }
            return 0;
        }
};
int main (){
    int x;
    cout << "please enter the number : ";
    cin >> x;
    Solution s1;
    cout << "your output is " << s1.mySqrt(x) << endl;
    return 0;
}
