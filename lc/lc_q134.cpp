#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost=0;
        int totalgas=0;
        for (int i=0;i<gas.size();i++){
            totalcost+=gas[i];
            totalgas+=cost[i];
        }
        if (totalcost>totalgas){
            return -1;
        }
        int start=0;
        int current=0;
        for (int i=0;i<gas.size();i++){
            current+=gas[i]-cost[i];
            if (current<0){current=0;start=i+1;}
        }
        return start;
    }
};
int main (){
    cout<< "enter the gas vector:";
    int y;
    vector<int>gas;
    while(cin>>y){
    gas.push_back(y);
    if(cin.peek()=='\n') break;
    }
    int x;
    vector<int>cost;
    while(cin>>x){
    gas.push_back(x);
    if (cin.peek()=='\n')break;
    }
    Solution sol;
    cout << endl<< sol.canCompleteCircuit(gas,cost);
    return 0;
}
