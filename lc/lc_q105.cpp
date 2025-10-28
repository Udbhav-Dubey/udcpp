#include <bits/stdc++.h>
using namespace std;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        unordered_map<int,int> map;
        for (int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        int index=0;
        return helper(preorder,inorder,index,0,inorder.size()-1,map);
    }
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int&index,int start,int end,unordered_map<int,int>&map){
        if (start>end)return nullptr;
        int rootval=preorder[index];
        TreeNode*root=new TreeNode(rootval);
        int mid=map[rootval];
        root->left=helper(preorder,inorder,index,start,mid-1,map);
        root->right=helper(preorder,inorder,index,mid+1,end,map);
        index++;
    }
};
