int dNodes[1001][2];

struct TreeNode* constructTree(const int * n, int * idx, int depth){
    if((*idx) >= (*n) || dNodes[(*idx)][0] < depth) return NULL;
    struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node->val = dNodes[(*idx)++][1];
    node->left = constructTree(n, idx, depth + 1);
    node->right = constructTree(n, idx, depth + 1);
    return node;
}

struct TreeNode* recoverFromPreorder(char* traversal) {
    const int n = strlen(traversal);
    int idx = 0;
    for (int i = 0; i < n;) {
        int hCount = 0;
        while (i < n && traversal[i] == '-') {
            i++;
            hCount++;
        }
        int num = 0;
        while (i < n && isdigit(traversal[i])) {
            num = (num * 10) + (traversal[i] - '0');
            i++;
        }
        dNodes[idx][0] = hCount;
        dNodes[idx++][1] = num;
    }
    const int nodes = idx;
    idx = 0;
    return constructTree(&nodes, &idx, 0);
}