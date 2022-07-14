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
    TreeNode* solve(vector<int>& preorder,int pstart, int pend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& in) {
        if(pstart > pend || instart > inend) return nullptr;
        TreeNode* root = new TreeNode(preorder[pstart]);
        
        int inroot = in[preorder[pstart]];
        int leftLen = inroot - instart;
        
        root->left = solve(preorder, pstart + 1, pstart + leftLen, inorder, instart, inroot - 1, in);
        root->right = solve(preorder,pstart + 1 + leftLen, pend, inorder, inroot + 1, inend, in);
        
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in;
        for(int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), in);
    }
};