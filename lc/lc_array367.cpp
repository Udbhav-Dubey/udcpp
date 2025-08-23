#include <bits/stdc++.h>
using namespace std;
class Solution{
    public :
        bool isPerfectSquare(int num){
            if (num==1){return true;}
            long int x=num;
            long int end=x;
            long int start=1;
            while (end>start){
                long int mid = start + (end-start)/2;
                if ((mid*mid)==x){return true;}
                if  ((mid*mid)<x && (mid+1)*(mid+1)>x) {return false;}
                if (mid*mid>x){
                    end=mid;
                }
                if (mid*mid<x){start=mid;}
            }
            return false;
        }
};
int main (){
    int x;
    cout << "please enter the number : ";
    cin >> x;
    Solution s1;
    cout << "your output is " << s1.isPerfectSquare(x) << endl;
    return 0;
}
