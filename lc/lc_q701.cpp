#include <iostream>
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr){return new TreeNode(val);}
        if (root->data>key){
            root->left=insertIntoBST(root->left,val);
        }
        else {root->right=insertIntoBST(root->right,val);}
        return root;
};
