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
    TreeNode* ans;
public:
    int findLCA(TreeNode* root, int req, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        
        int left = findLCA(root->left, req, p, q);
        int right = findLCA(root->right, req, p, q);
        
        int total = left + right;
        if (root == p || root == q) {
            total++;
        }
        
        if (total >= req && !ans) {
            ans = root;
        }
        
        return total;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        findLCA(root, 2, p, q);
        return ans;
    }
};