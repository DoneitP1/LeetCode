#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define MAX_NODES 200
#define MAX_EDGES 6000

typedef struct { int v; long long t; } Edge;
Edge graph[MAX_NODES][MAX_NODES];
int gSize[MAX_NODES];

typedef struct { long long t; int n; } HeapNode;
HeapNode heap[MAX_NODES];
int hSize = 0;

void push(long long t, int n) {
    int i = hSize++;
    while (i && heap[(i - 1) / 2].t > t) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = (HeapNode){t, n};
}

HeapNode pop() {
    HeapNode min = heap[0], last = heap[--hSize];
    int i = 0, child;
    while ((child = 2 * i + 1) < hSize) {
        if (child + 1 < hSize && heap[child + 1].t < heap[child].t) child++;
        if (last.t <= heap[child].t) break;
        heap[i] = heap[child], i = child;
    }
    heap[i] = last;
    return min;
}

int countPaths(int n, int** roads, int roadsSize, int* roadsColSize) {
    long long dist[MAX_NODES];
    int ways[MAX_NODES];

    for (int i = 0; i < n; i++) dist[i] = LLONG_MAX, ways[i] = 0, gSize[i] = 0;

    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0], v = roads[i][1];
        long long t = roads[i][2]; // Use long long
        graph[u][gSize[u]++] = (Edge){v, t};
        graph[v][gSize[v]++] = (Edge){u, t};
    }

    dist[0] = 0, ways[0] = 1, hSize = 0, push(0, 0);

    while (hSize) {
        HeapNode min = pop();
        int u = min.n;
        long long t = min.t;
        if (t > dist[u]) continue;

        for (int i = 0; i < gSize[u]; i++) {
            int v = graph[u][i].v;
            long long newT = t + graph[u][i].t; // Avoid overflow

            if (newT < dist[v]) dist[v] = newT, ways[v] = ways[u], push(newT, v);
            else if (newT == dist[v]) ways[v] = (ways[v] + ways[u]) % MOD;
        }
    }
    return ways[n - 1];
}