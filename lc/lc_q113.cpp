#include <iostream>
class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        helper(root,targetSum,path,res);
        return res;
    }
    void helper(TreeNode*root,int targetSum,vector<int>&path,vector<vector<int>>&res){
        if (!root)return ;
        path.push_back(root->val);
        targetSum-=root->val;
        if (root->left==nullptr&&root->right==nullptr&&targetSum==0){
            res.push_back(path);
        }
        else {
            helper(root->left,targetSum,path,res);
            helper(root->right,targetSum,path,res);
        }
        path.pop_back();
    }
};
