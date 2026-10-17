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
    int chkHt(TreeNode* root) {
        if(root==nullptr) return 0;

        int leftHt = chkHt(root->left);
        if(leftHt==-1) return -1;

        int rightHt = chkHt(root->right);
        if(rightHt==-1) return -1;

        if(abs(leftHt - rightHt) > 1) return -1;

        return 1 + max(leftHt, rightHt);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        return chkHt(root)!=-1;

        
    }
};

