#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.back();
        int size = digits.size();
        for (int i=size-1;i>=0;--){
            if (digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;

    }};
int main (){
    vector <int> digits;
    cout << "please enter the array : ";

return 0;
}
