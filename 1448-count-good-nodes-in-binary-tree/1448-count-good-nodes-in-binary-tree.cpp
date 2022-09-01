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
    int cnt = 0;
    void dfs(TreeNode* root, int curMax) {
        if(root->val >= curMax) {
            cnt++;
            curMax = root->val;
        }
        if(root->left) dfs(root->left, curMax);
        if(root->right) dfs(root->right, curMax);
    }
    
public: 
    int goodNodes(TreeNode* root) {
        int curMax = root->val;
        dfs(root, curMax);
        
        return cnt;
    }
};