/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if( root == NULL ) return NULL;

    struct TreeNode *tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree->val = root->val;
    tree->left = invertTree(root->right);
    tree->right = invertTree(root->left);

    return tree;
}