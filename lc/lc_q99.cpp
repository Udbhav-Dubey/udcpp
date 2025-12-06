class Solution {
public:
    TreeNode*prev=nullptr;
    TreeNode*first=nullptr;
    TreeNode*second=nullptr;
    void recoverTree(TreeNode* root){
        if (!root){return ;}
        inorder(root); 
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    } 
    void inorder(TreeNode*root){
        if (!root){return ;}
        inorder(root->left);
        if (prev&&prev->val>root->val){
            if (first==nullptr){
                first=prev;
                second=root;
            }
            else second=root;
        }
        prev=root;
        inorder(root->right);
    }
};
