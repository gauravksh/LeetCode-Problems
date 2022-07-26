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
    unordered_map<TreeNode*, bool> mp;
    TreeNode* ans;
public:
    int findLCA(TreeNode* root, int req, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        
        int left = findLCA(root->left, req, p, q);
        int right = findLCA(root->right, req, p, q);
        
        int total = left + right;
        if (mp[root] == true) {
            total++;
        }
        
        if (total >= req && !ans) {
            ans = root;
        }
        
        return total;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp[p] = true;
        mp[q] = true;
        ans = nullptr;
        findLCA(root, 2, p, q);
        return ans;
    }
};