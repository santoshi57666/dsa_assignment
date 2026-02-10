(a) Data Structures Used

graph[MAX][MAX]
A weighted adjacency matrix used to store graph edges.
INF = 99999 indicates no direct edge between vertices.

dist[MAX]
Stores the shortest distance from the source vertex to every other vertex.

visited[MAX]
Keeps track of vertices that have already been processed.

parent[MAX]
Stores the predecessor of each vertex to reconstruct the shortest path.

Initially, the distance of the source vertex is set to 0, and all other distances are set to INF.

(b) Functions Implemented

dijkstra(n, start)
Implements Dijkstra’s greedy algorithm to find the shortest path from the source vertex to all other vertices.

printPath(n, start)
Prints the shortest distance and the complete path from the source to each destination using the parent array.

(c) Organization of main()

Creates a weighted undirected graph with 6 vertices.

Displays the adjacency matrix of the graph.

Calls dijkstra(6, 0) to find shortest paths from source vertex 0.

Prints all shortest paths and their distances.

(d) Sample Output
Adjacency Matrix:
  0   4   2 INF INF INF 
  4   0   1   5 INF INF 
  2   1   0   8  10 INF 
INF   5   8   0   2   6 
INF INF  10   2   0   3 
INF INF INF   6   3   0 

Shortest paths from source 0:
To 1: 3 (path: 1->2->0)
To 2: 2 (path: 2->0)
To 3: 8 (path: 3->1->2->0)
To 4: 10 (path: 4->3->1->2->0)
To 5: 13 (path: 5->4->3->1->2->0)