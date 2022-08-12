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
    int solve(TreeNode* root, TreeNode*& p, TreeNode*& q, TreeNode*& lca) {
        if(!root) return 0;
        int left = solve(root->left, p, q, lca);
        int right = solve(root->right, p, q, lca);
        int cur = 0;
        if(root->val == p->val || root->val == q->val) cur++;
        if(left + right + cur >= 2) lca = root;
        
        return left || right ||cur; 
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = nullptr;
        solve(root, p, q, ancestor);   
        
        return ancestor;
    }
};