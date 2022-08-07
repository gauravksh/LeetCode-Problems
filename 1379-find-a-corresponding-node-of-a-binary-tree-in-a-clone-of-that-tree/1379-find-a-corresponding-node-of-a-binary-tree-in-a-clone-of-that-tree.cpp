class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;
        TreeNode* node = getTargetCopy(original->left, cloned->left, target);
        if (node) return node;
        node = getTargetCopy(original->right, cloned->right, target);
        if (node) return node;
        return nullptr;
    }
};