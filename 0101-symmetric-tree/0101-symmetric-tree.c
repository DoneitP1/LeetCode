/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* child1, struct TreeNode* child2) {
    if (!child1 || !child2)
        return child1 == child2;
    else
        return (child1->val == child2->val) && isMirror(child1->left, child2->right) && isMirror(child1->right, child2->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root->left, root->right);
}
