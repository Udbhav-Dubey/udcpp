#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> answer(mat.size(),vector<int>(mat[0].size()));
        vector<vector<int>> prefix(mat.size()+1,vector<int>(mat[0].size()+1,0));
        for (int i=0;i<mat.size();++i){
            for (int j=0;j<mat[0].size();++j){
                prefix[i+1][j+1]=mat[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
            }
        }
        for (int i=0;i<mat.size();i++){
            int r1=max(0,i-k);
            int r2=min(0,i+k);
            for (int j=0;i<mat[i].size();i++){
                int c1=max(0,j-k);
                int c2=min(0,j+k);
                answer[i][j]=prefix[r2+1][c2+1]-prefix[r1][c2+1]-prefix[r2+1][c1]+prefix[r1][c1];
            }
            
        }
        return answer;
    }
};
int main (){
    int m,n;
    cout << "enter the m and n for size of matrix : ";
    cin >> m >> n ;
    cout << "enter the vector : ";
    vector <vector<int>> mat(m,vector<int>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    int k;
    cout << "enter the k : ";
    cin >> k;
    Solution sol;
    vector<vector<int>> answer=sol.matrixBlockSum(mat,k);
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout << answer[i][j];
        }
    }
return 0;
}
