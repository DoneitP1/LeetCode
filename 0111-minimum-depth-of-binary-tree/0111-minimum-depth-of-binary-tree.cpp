class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = minDepth(root -> left), r = minDepth(root -> right);
        return (l == 0 or r == 0) ? 1 + max(l, r) : 1 + min(l, r);
    }
};