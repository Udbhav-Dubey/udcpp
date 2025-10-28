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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr){return {} ;}
        deque<TreeNode*>d;
        d.push_back(root);
        int flag=0;
        vector<vector<int>>ans;
        while(!d.empty()){
            int len=d.size();
            ans.push_back({});
            for (int i=0;i<len;i++){
            if (flag==0){
            TreeNode * node=d.front();
            d.pop_front();
            ans.back().push_back(node->val);
            if (node->left) d.push_back(node->left);
            if (node->right)d.push_back(node->right);
            }
            else {
            TreeNode*node=d.back();
            d.pop_back();
            ans.back().push_back(node->val);
            if (node->right) d.push_front(node->right);
            if (node->left) d.push_front(node->left);
            }
            }
            flag=!flag;
        }
        return ans;
    }
};
