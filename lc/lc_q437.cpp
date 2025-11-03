#include <bits/stdc++.h>
class Solution {
public:
    int count=0;
    int current=0;
    int pathSum(TreeNode* root, int targetSum){
       unordered_map<long long ,int> pre;
           pre[0]=1;
           return dfs(root,targetSum,pre);
    } 
    int dfs(TreeNode*root,int targetSum,unordered_map<long long ,int>&pre){
        if (!root){return 0;} 
        current+=node->val;
        int count=0;
        if (pre.count(current-target)){
            count+=pre[current-target];
        }
        pre[current]++;
        count+=dfs(root->left,targetSum,pre);
        count+=dfs(root->right,targetSum,pre);
        pre[current]--;
        return count;
    }
};
