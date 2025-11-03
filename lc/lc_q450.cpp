class Solution {
public:
    Node*getsuccessor(TreeNode*curr){
        curr=curr->right;
        while(curr!=nullptr&&curr->left!=nullptr){
            curr=curr->left;
            return curr;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr){return nullptr;}
            if (root->data>key){
                root->left=deleteNode(root->left,key);
            }
            else if (root->data<key){
                root->right=deleteNode(root->right,key);
            }
            else {
                if (root->left==nullptr){
                    TreeNode*temp=root->right;
                    delete root;
                    return temp;
                }
                if (root->right==nullptr){
                    TreeNode*temp=root->left;
                    delete root;
                    return temp;
                }
            
            Node*succ=getsuccessor(curr);
            root->data=succ->data;
            root->right=delNode(root->right,succ->data);
            }
            return root;
    }
};
