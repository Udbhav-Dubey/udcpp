/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr){return true;}
        return doublerecurse(root->left,root->right);
    }
    bool doublerecurse(TreeNode*l1,TreeNode*r1){
        if (l1==nullptr && r1==nullptr){
            return true;
        }
        if (l1==nullptr||r1==nullptr){
            return false;
        }
        return r1->val==l1->val && doublerecurse(l1->left,r1->right)&&doublerecurse(l1->right,r1->left); 
    }
};
