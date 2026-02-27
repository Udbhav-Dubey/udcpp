#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0){return 0;}
        queue<int>q;
        q.push(0);
        vector<bool>visited(amount+1,false);
        visited[0]=1;
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            steps++;
            for (int i=0;i<n;i++){
                int temp=q.front();
                q.pop();
                for (int &coin:coins){
                    int val=coin+temp;
                    if (val==amount){return steps;}
                    if (val<amount&&!visited[val]){
                        q.push(val);
                        visited[val]=1;
                    }
                }
            }
        }
        return -1;
    }
};
