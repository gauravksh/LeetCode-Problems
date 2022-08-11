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
    bool solve(TreeNode* root, TreeNode*& prev) {
        if(!root) return true;
        if(!solve(root->left, prev)) return false;
        if(prev) {
            if(prev->val >= root->val) return false;
        }
        prev = root;
        return solve(root->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return solve(root, prev);
    }
};