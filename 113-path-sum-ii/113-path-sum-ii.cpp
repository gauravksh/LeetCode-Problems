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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int cur, vector<int>& res) {
        if(!root->left && !root->right && cur == 0) {
            ans.push_back(res);
            return;
        }
        else {
            if(root->right) {
                int right = root->right->val;
                cur -= right;
                res.push_back(right);
                solve(root->right, cur, res);
                cur += right;
                res.pop_back();
            }
            if(root->left) {
                int left = root->left->val;
                cur -= left;
                res.push_back(left);
                solve(root->left, cur, res);
                cur += left;
                res.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> res = {root->val};
        solve(root, targetSum - root->val, res);
        
        return ans;
    }
};