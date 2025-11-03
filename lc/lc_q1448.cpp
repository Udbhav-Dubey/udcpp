class Solution {
public:
    int goodNodes(TreeNode* root) {
        int maxnode=0;
        return dfs(root,maxnode)       
    }
    void dfs(TreeNode*root,int maxnode){
        if (root==nullptr){
            return ;
        }
        int count=0;
        if (root->val>=maxnode){
            count++;
            maxnode=root->val;
        }
        count+=dfs(root->left,maxnode);
        count+=dfs(root->right,maxnode);
        return count;
    }
};
