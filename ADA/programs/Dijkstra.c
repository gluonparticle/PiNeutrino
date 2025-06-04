#include <stdio.h>
#include <limits.h>

#define INF INT_MAX


void dijkstra(int V, int adj[V][V], int dist[V]) {
    int visited[V];


    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;  // Source is 0

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u != -1)  visited[u] = 1;
       

        // Relax neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] &&    dist[u] != INF &&    dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int adj[V][V], dist[V];

    printf("Enter adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &adj[i][j]);

    dijkstra(V, adj, dist);

    printf("Distances from source (0):\n");
    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}