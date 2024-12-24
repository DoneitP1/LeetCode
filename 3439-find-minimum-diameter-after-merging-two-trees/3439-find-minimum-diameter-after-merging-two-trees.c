
#define MAX_NODES 100000

struct node {
  struct node *next;
  int vertex;
  int padding;
};

typedef struct node node;

node arena[(MAX_NODES << 1)];
node *adjecancy_list[MAX_NODES];

int dfs(int child, int parent, int *diameter) {
  node* tourist = adjecancy_list[child];
  int max1, max2;
  max1 = 0;
  max2 = 0;
  while (tourist != NULL) {
    if (tourist->vertex != parent) {
      int candidate = dfs(tourist->vertex, child, diameter);
      if (max1 <= candidate) {
        max2 = max1;
        max1 = candidate;
      }
      else if (max2 < candidate) {
        max2 = candidate;
      }
    }
    tourist = tourist->next;
  }
  if (*diameter < max1 + max2) {
    *diameter = max1 + max2;
  }
  return max1 + 1;
}

int get_diameter(int **edges, int edgesSize)
{
  int a, b;
  int index = 0;
  for (int i = 0; i <= edgesSize; ++i) {
    adjecancy_list[i] = NULL;
  }
  for (int i = 0; i < edgesSize; ++i) {
    a = edges[i][0];
    b = edges[i][1];

    arena[index].vertex = b;
    arena[index].next = adjecancy_list[a];
    adjecancy_list[a] = arena + index++;

    arena[index].vertex = a;
    arena[index].next = adjecancy_list[b];
    adjecancy_list[b] = arena + index++;
  }
  int diameter = 0;
  dfs(0, -1, &diameter);
  return diameter;
}

int minimumDiameterAfterMerge(int** edges1, 
                              int edges1Size, 
                              int* edges1ColSize, 
                              int** edges2, 
                              int edges2Size, 
                              int* edges2ColSize) 
{
  int d1 = get_diameter(edges1, edges1Size); 
  int d2 = get_diameter(edges2, edges2Size);

  int ans = 1 + (d1 + 1) / 2 + (d2 + 1) / 2;

  if (d1 > ans) {
    ans = d1;
  }
  if (d2 > ans) {
    ans = d2;
  }
  return ans;
}