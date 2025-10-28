class Solution {
public:
    vector<int> ans;
    void travel(TreeNode*root,int level){
        if (root==nullptr){return ;}
        if (level==ans.size()){ans.push_back(root->val);}
        travel(root->right,level+1);
        travel(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        travel(root,0);
        return ans;
    }
};
