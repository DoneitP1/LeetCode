void dfs(struct TreeNode* left, struct TreeNode* right, int level) {
    bool rev = level & 0x01;
    if(!left && !right) return;
    if(!left) {
        return dfs(right->left, right->right, level + 1);
    }

    if(!right) {
        return dfs(left->left, left->right, level + 1);
    }

    if(rev) {
        int lval = left->val;
        int rval = right->val;
        left->val = rval;
        right->val = lval;
    }

    dfs(left->left, right->right, level + 1);
    dfs(left->right, right->left, level + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    dfs(root, NULL, 0);

    return root;
}