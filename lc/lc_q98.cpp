class Solution {
public:
    bool isValid=true;
    TreeNode*prev=nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root){return false;}
        inorder(root);
        return isValid;
    }
    void inorder(TreeNode*root){
        if (!root){return ;}
        inorder(root->left);
        if (prev!=nullptr&&prev->val>=root->val){
            isValid=false;
        }
        prev=root;
        inorder(root->right);
    }
};
