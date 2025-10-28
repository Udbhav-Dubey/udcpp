class Solution{
    public:
        TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder){
            unordered_map<int,int> map;
            for (int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
            }
            int index=0;
            return helper(inorder,postorder,index,0,inorder.size()-1,map);
        }
        TreeNode* helper(vector<int>&inorder,vector<int>&postorder,int&index,int start , int end,unordered_map<int,int>&map){
            if (start>end){return nullptr;} 
            int rootval=postorder[index++];
            TreeNode*root=new TreeNode(rootval);
            int mid=map[rootval];
            root->left=helper(inorder,postorder,index,start,mid-1,map);
            root->right=helper(inorder,postorder,index,mid+1,end,map);
            return root;
        }
};
