/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* solve(TreeNode* root, TreeNode*& p, TreeNode*& q) {
        if(!root) return nullptr;
        int val = root->val;
        if(p->val > val && q->val > val) return solve(root->right, p, q);
        else if(p->val < val && q->val < val) return solve(root->left, p, q);
        else return root;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);   
    }
};