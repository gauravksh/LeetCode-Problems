class Solution {
    int getLevels(TreeNode* root) {
        if(!root) return 0;
        
        int leftLvl = getLevels(root->left);
        int rightLvl = getLevels(root->right);
        
        return 1 + max(leftLvl,rightLvl);
    }
    
    void solve(TreeNode* root, vector<int>& res, int lvl) {
        if(root == nullptr) return;
        res[lvl] = root->val;
        solve(root->left, res, lvl + 1);
        solve(root->right, res, lvl + 1);
    } 
public:
    vector<int> rightSideView(TreeNode* root) {
        int lvl = getLevels(root);
        vector<int> res(lvl);
        solve(root, res, 0);
        return res;
    }
};