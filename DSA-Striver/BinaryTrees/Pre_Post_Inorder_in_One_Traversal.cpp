/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
        void traverse(TreeNode* root, vector<int>& in, vector<int>& pre, vector<int>& post){
            if(root==nullptr) return;
            pre.push_back(root->data);
            traverse(root->left, in, pre, post);

            in.push_back(root->data);
            traverse(root->right,in,pre,post);

            post.push_back(root->data);
        }
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
            vector<int> in, pre, post;
            traverse(root, in, pre, post);

            return{in, pre, post};

			
		}
};

