#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backtrack(vector<vector<char>>&board,string &word,int i,int j,int index){
        if (index==word.size()){
            return true;
        }
        if (i<0||i>=board.size()||j<0||j>=board[i].size()||board[i][j]!=word[index]){
            return false;
        }
        char temp=board[i][j];
        bool found=backtrack(board,word,i+1,j,index+1)||backtrack(board,word,i-1,j,index+1)||backtrack(board,word,i,j-1,index+1)||backtrack(board,word,i,j+1,index+1);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
           string muller;
           int index=0;
        int  m = board.size();
        for (int i=0;i<m;i++){
           int n=board[i].size();
           for(int j=0;j<n;j++){
                if (board[i][j]==word[0]) {
                    if (backtrack(board,word,i,j,index){return true;}}
           } }}
           return false;
};
int main (){return 0;}
