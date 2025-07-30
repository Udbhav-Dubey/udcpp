#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        int count=0;
        for (int factor=1;factor<=n;factor*=10){
            int curr=(n/factor)%10;
            int low=n%factor;
            int high=n/(factor*10);
            if (curr==0){
                count+= high * factor;
            }
            else if (curr==1){
                count+=high*factor+low+1;
            }
            else{count+=(high+1)*factor;}
        }
        return count;
    }
};
int main (){
    int n;
    cin>>n;
    Solution sol;
    cout << "answer : " << sol.countDigitOne(n);
    return 0;
}
