class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr){return false;}
        int sum+=root->val;
        if (sum==targetSum && root->left==nullptr && root->right==nullptr){
            return false;
        }
        return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);
    }
};
