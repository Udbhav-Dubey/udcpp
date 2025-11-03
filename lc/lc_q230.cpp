#include <iostream>
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root==nullptr){return -1;}
        vector<int> ans;
        makevec(root,ans);
        return ans[k-1];
    }
    void makevec(TreeNode*root,vector<int>&ans){
        if(root==nullptr){return ;} 
        makevec(root->left,ans);
        ans.push_back(root->data);
        makevec(root->right,ans);
    }
};
