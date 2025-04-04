/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postOrder(struct TreeNode* root, int* num, int* size){
    if(root==NULL) return;
postOrder(root->left, num, size);
        postOrder(root->right, num, size);
        num[(*size)++]=root->val;

        }
        int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr=(int*)malloc(100*sizeof(int));
    *returnSize=0;
    postOrder(root, arr, returnSize);
    return arr;
}
