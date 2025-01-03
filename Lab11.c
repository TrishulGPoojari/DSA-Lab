/*11. Develop a Program in C for the following operations on Graph(G) of Cities 
a. Create a Graph of N cities using Adjacency Matrix. 
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS 
method */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

// Function prototype for BFS
void bfs(int n, int source, int visited[], int admat[][SIZE]);

void main()
{
    int admat[SIZE][SIZE], source, i, j, n, visited[SIZE] = {0};

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter graph adjacency matrix (AM):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) { 
            scanf("%d", &admat[i][j]);
        }
    }

    printf("Enter source vertex:\n");
    scanf("%d", &source);

    // Perform BFS from the source vertex
    bfs(n, source, visited, admat);

    // Display the result for each vertex
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("%d is not reachable\n", i);
        } else {
            printf("%d is reachable\n", i);
        }
    }
}

void bfs(int n, int source, int visited[], int admat[][SIZE])
{
    int q[SIZE], u, v, r = 0, f = 0;        //Making use of queue to keeping updating the source value or the node value 

    visited[source] = 1;  // Mark source as visited
    q[r++] = source;        // Enqueue the source

    while (f < r) {
        u = q[f++];  // Dequeue a vertex and to search that particular row  
        for (v = 0; v < n; v++) {
            if (admat[u][v] == 1 && visited[v] == 0) {  // If edge exists and vertex is unvisited
                visited[v] = 1;  // Mark as visited
                q[r++] = v;      // Enqueue the vertex
            }
        }
    }
}
