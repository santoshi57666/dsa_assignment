#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX];
int vertices;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};
    
    printf("BFS starting from vertex %d: ", start);
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
  
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int visited[MAX];

void DFSUtil(int v) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFSUtil(i);
        }
    }
}

void DFS(int start) {
    printf("DFS starting from vertex %d: ", start);
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    DFSUtil(start);
    printf("\n");
}

void createExampleGraph() {
    vertices = 4;
    
    
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    
    graph[0][1] = graph[1][0] = 1;  // 0-1
    graph[0][2] = graph[2][0] = 1;  // 0-2
    graph[1][2] = graph[2][1] = 1;  // 1-2
    graph[1][3] = graph[3][1] = 1;  // 1-3
    graph[2][3] = graph[3][2] = 1;  // 2-3
}

int main() {
    createExampleGraph();
    
    printf("Undirected Graph (Adjacency Matrix):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    
    printf("\n");
    BFS(0);
    DFS(0);
    
    return 0;
}
