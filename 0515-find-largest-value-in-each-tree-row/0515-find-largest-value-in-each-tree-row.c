#define MAX 10000
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef struct TreeNode TreeNode;

int *largestValues(struct TreeNode *root, int *returnSize)
{
  int *ans = (int *)malloc(sizeof(int) * 10000);
  if (!root)
  {
    (*returnSize) = 0;
    return ans;
  }

  TreeNode *nodes[MAX];
  TreeNode *newNodes[MAX];
  newNodes[0] = root;

  int len = 0, newLen = 1, ansSize = 0, temp, levelMax;
  TreeNode **nodePtr = nodes, **newNodePtr = newNodes, **tempPtr;
  while (newLen)
  {

    tempPtr = newNodePtr;
    newNodePtr = nodePtr;
    nodePtr = tempPtr;

    len = newLen;
    newLen = 0;

    levelMax = nodePtr[0]->val;
    for (int i = 0; i < len; i++)
    {
      levelMax = max(nodePtr[i]->val, levelMax);
      if (nodePtr[i]->left)
      {
        newNodePtr[newLen++] = nodePtr[i]->left;
      }
      if (nodePtr[i]->right)
      {
        newNodePtr[newLen++] = nodePtr[i]->right;
      }
    }
    ans[ansSize++] = levelMax;
  }

  (*returnSize) = ansSize;
  return ans;
}