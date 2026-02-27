#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for (int i=0;i<n;i++){
            vector<bool>flag(n,0);
            for (int j=0;j<n;j++){
                if (board[i][j]=='.'){continue;}
                if (flag[board[i][j]]==1){return false;}
                flag[board[i][j]]=1;
            }
        }
        for (int j=0;j<n;j++){
            vector<bool>flag(n,0);
            for (int i=0;i<n;i++){
                if (board[i][j]=='.'){continue;}
                if (flag[board[i][j]]==1){return false;}
                flag[board[i][j]]=1;
            }
        }
        for(int box=0;box<9;box++){
            int r=(box%3)*3;
            int c=(box/3)*3;
            vector<bool>flag(n,0);
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                 if (board[r+i][j+c]=='.'){continue;}                   
                    if (flag[board[r+i][c+j]]==1){return false;}
                    flag[board[r+i][c+j]]=1;
                }
            }
        }
        return true;
    }
};
int main (){

    return 0;
}
