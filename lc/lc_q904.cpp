#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
                int last_seen=-1
                int second_last=-1;
                int left=0;
                int current_max,max_size;
                for (int i=0;i<fruits.size();i++){
                    if (last_seen==fruits[i]||second_last=fruits[i]){
                        current_max++;
                    }
                    else {current_max=left+1;}
                    if (fruit[i]==last_seen){
                        left++;
                    }
                    else {
                        last_count=1;
                        second_last=last_seen;
                        last_fruit=fruit[i];
                    }
                    max_size=max(current_max,max_size);
                }
                return max_size;
        }
};
int main (){
    cout << "enter the fruits array : ";
    int x;
    vector <int>fruits;
    while(cin>>x){
        fruits.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    cout << "your answer is " << sol.totalFruit(fruits);
return 0;
}
