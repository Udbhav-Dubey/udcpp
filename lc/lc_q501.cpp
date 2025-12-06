class Solution {
public:
    TreeNode* prev = nullptr;
    int currCount = 0;
    int maxCount = 0;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (!prev || prev->val != root->val) {
            currCount = 1;
        } else {
            currCount++;
        }
        if (currCount > maxCount) {
            maxCount = currCount;
            res.clear();
            res.push_back(root->val);
        } else if (currCount == maxCount) {
            res.push_back(root->val);
        }
        prev = root;
        inorder(root->right);
    }
};

