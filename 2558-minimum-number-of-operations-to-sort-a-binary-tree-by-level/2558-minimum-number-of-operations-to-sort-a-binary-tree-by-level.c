#define MAX 34472
typedef struct TreeNode TreeNode;

typedef struct
{
  TreeNode *node;
  int index;
} NodeIndex;

int cmp(const void *ptr1, const void *ptr2)
{
  NodeIndex *tptr1 = (NodeIndex *)ptr1;
  NodeIndex *tptr2 = (NodeIndex *)ptr2;

  if ((*tptr1).node->val > (*tptr2).node->val)
    return 1;
  return -1;
}

int minimumOperations(struct TreeNode *root)
{
  NodeIndex nodes[MAX];
  NodeIndex newNodes[MAX];
  newNodes[0].node = root;

  int len = 0, newLen = 1, temp, ans = 0;
  NodeIndex *nodePtr = nodes, *newNodePtr = newNodes, *tempPtr;
  while (newLen)
  {
    tempPtr = newNodePtr;
    newNodePtr = nodePtr;
    nodePtr = tempPtr;

    len = newLen;
    newLen = 0;

    for (int i = 0; i < len; i++)
    {
      if (nodePtr[i].node->left)
      {
        newNodePtr[newLen].index = newLen;
        newNodePtr[newLen++].node = nodePtr[i].node->left;
      }
      if (nodePtr[i].node->right)
      {
        newNodePtr[newLen].index = newLen;
        newNodePtr[newLen++].node = nodePtr[i].node->right;
      }
    }

    qsort(nodePtr, len, sizeof(NodeIndex), cmp);
    for (int i = 0; i < len; i++)
    {
      while (nodePtr[i].index != i)
      {
        ans++;
        
        temp = nodePtr[i].index;
        nodePtr[i].index = nodePtr[nodePtr[i].index].index;
        nodePtr[temp].index = temp;
      }
    }
  }
  return ans;
}