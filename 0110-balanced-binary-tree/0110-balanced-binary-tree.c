/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int heightOfTree(struct TreeNode* root){
    if(root){
        int lh, rh;
        lh = heightOfTree(root->left);
        rh = heightOfTree(root->right);
        return (lh > rh ? lh : rh)+1;
    }
    return 0;
}

bool isBalanced(struct TreeNode* root) {
    if (!root){return true;}
    int lh,rh;
    lh = heightOfTree(root->left);
    rh = heightOfTree(root->right);
    return (abs(lh-rh) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}