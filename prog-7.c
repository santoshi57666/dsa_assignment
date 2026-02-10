#include <stdio.h>
#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

void dijkstra(int n, int start)
 {
    for (int i = 0; i < n; i++)
     {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (int count = 0; count < n; count++)
     {
        int u = -1;
        int minDist = INF;
        
        for (int v = 0; v < n; v++)
         {
            if (!visited[v] && dist[v] < minDist)
             {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        visited[u] = 1;
        
        for (int v = 0; v < n; v++)
         {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printPath(int n, int start) {
    printf("\nShortest paths from source %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("To %d: ", i);
            if (dist[i] == INF) {
                printf("No path\n");
            } else {
                printf("%d (path: ", dist[i]);
                int j = i;
                while (j != -1) {
                    printf("%d", j);
                    j = parent[j];
                    if (j != -1) printf("->");
                }
                printf(")\n");
            }
        }
    }
}

int main()
 {
    int n = 6;  
    int source = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    graph[0][1] = 4; graph[1][0] = 4;
    graph[0][2] = 2; graph[2][0] = 2;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[1][3] = 5; graph[3][1] = 5;
    graph[2][3] = 8; graph[3][2] = 8;
    graph[2][4] = 10; graph[4][2] = 10;
    graph[3][4] = 2; graph[4][3] = 2;
    graph[3][5] = 6; graph[5][3] = 6;
    graph[4][5] = 3; graph[5][4] = 3;
    
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) printf("INF ");
            else printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    
    dijkstra(n, source);
    printPath(n, source);
    
    return 0;
}
