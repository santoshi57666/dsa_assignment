(a) Data Structures
Adjacency Matrix for Undirected Graph:

int graph[MAX][MAX];  // MAX=100, graph[i][j]=1 if edge exists between i,j
int vertices;         // Number of vertices in graph
int visited[MAX];     // Tracks visited vertices
int queue[MAX];       // BFS queue array
Symmetric matrix: graph[i][j] = graph[j][i] for undirected edges

Space: O(V²) where V=vertices

(b) Functions Implemented
BFS(int start): Queue-based level-order traversal from start vertex
DFSUtil(int v): Recursive DFS helper (marks visited, explores neighbors)
DFS(int start): Initializes visited array, calls DFSUtil
createExampleGraph(): Builds sample 4-vertex connected graph

(c) main() Organization
1. Call createExampleGraph() → builds 4-vertex graph
2. Print adjacency matrix
3. Execute BFS traversal from vertex 0
4. Execute DFS traversal from vertex 0

(d) Sample Output
Undirected Graph (Adjacency Matrix):
0 1 1 0 
1 0 1 1 
1 1 0 1 
0 1 1 0 

BFS starting from vertex 0: 0 1 2 3 
DFS starting from vertex 0: 0 1 2 3 