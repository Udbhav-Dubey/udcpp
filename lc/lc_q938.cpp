#include <bits/stdc++.h>
using namespace std;
class Solution {
    public :
        int rangeSumBST(TreeNode*root,int low,int high){
            if (root==nullptr){return 0;}
            int answer=0;
            if (root->data<=high&&root->data>=low){
                answer+=root->data;
            }
            answer+=rangeSumBst(root->left,low,high);
            answer+=rangeSumBst(root->right,low,high);
            return answer;
        }
};
