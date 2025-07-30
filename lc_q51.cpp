#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(int n,int row,unordered_set<int>&colm,unordered_set<int>&dia1,unordered_set<int>&dia2,vector<string>&muller,vector<vector<string>> &result){
        if (row==n){
                    result.push_back(muller);
                
            return ;}
        for (int col=0;col<n;col++){
            int diag1=row+col;
            int diag2=(col>row)?col-row:row-col;
            if (colm.count(col)==0 && dia1.count(diag1)==0 && dia2.count(diag2)==0){
                muller[row][col]='Q';
            
            dia1.insert(diag1);
            dia2.insert(diag2);
            colm.insert(col);
            }
            backtrack(n,row+1,colm,dia1,dia2,muller,result);
            muller[row][col]='.';
            dia1.erase(diag1);
            dia2.erase(diag2);
            colm.erase(col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> result;
       vector<string>muller(n,string(n,'.'));
        unordered_set<int> col,dia1,dia2;
        backtrack(n,0,col,dia1,dia2,muller,result);
        return result;
    }
};
int main (){
    cout << "enter the n : ";
    int n;
    cin>>n;
    Solution sol;
return 0;
}
