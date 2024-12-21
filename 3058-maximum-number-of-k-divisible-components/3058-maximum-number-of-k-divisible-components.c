#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 30000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX_NODES]; 
int count = 0;        


void addEdge(int a, int b) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = b;
    newNode->next = adj[a];
    adj[a] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = a;
    newNode->next = adj[b];
    adj[b] = newNode;
}


long long dfs(int node, int parent, int* values, int k) {
    long long sum = values[node]; 

    
    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (neighbor != parent) { 
            sum += dfs(neighbor, node, values, k); 
        }
        temp = temp->next;
    }

    
    if (sum % k == 0) {
        count++;
        return 0;
    }

    return sum; 
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        addEdge(a, b);
    }

    count = 0;

    dfs(0, -1, values, k);

    return count;
}

void freeGraph(int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        adj[i] = NULL;
    }
}