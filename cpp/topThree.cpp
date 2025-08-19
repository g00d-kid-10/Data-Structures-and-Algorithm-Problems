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
private:
	vector<string> ans;

public:

    void dfs(TreeNode* root, string str) {
        if(!root->left && !root->right) {
        	ans.push_back(temp);
        	return;
        }

        str += root->val + "->";

        if(root->left) {
        	dfs(root->left, temp);
        } else if(root->right) {
        	dfs(root->right, temp);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};