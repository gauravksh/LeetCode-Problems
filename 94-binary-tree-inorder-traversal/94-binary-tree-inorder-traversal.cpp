class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        
        vector<int> cur = left;
        cur.push_back(root->val);
        cur.insert(cur.end(), right.begin(), right.end());
        return cur;
    }
};