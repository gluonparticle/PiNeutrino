#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int visited[10] = {0}, cost[10][10], mincost = 0;
int i, j, a, b, u, v, ne = 1;

int main() {
    int num;

    printf("\nPrim's Algorithm\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;  // Replace 0 with a large value (no edge)
        }
    }

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");
    for (i = 0; i < num; i++) {
        visited[i] = 0;  // Initialize visited array
    }

    visited[0] = 1;  // Start from node 0

    while (ne < num) {
        int min = INF;
        for (i = 0; i < num; i++) {
            for (j = 0; j < num; j++) {
                if (visited[i] && !visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        printf("Edge %d: (%d - %d) cost: %d\n", ne++, a, b, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INF;  // Mark edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}


// Example input : 
// 4 

/*
0 10 6 5 
10 0 0 15
6 0 4 0
5 15 0 0
*/// Example output :
// Edges in the Minimum Cost Spanning Tree:
// Edge 1: (0 - 3) cost: 5
// Edge 2: (0 - 2) cost: 6

// Edge 3: (2 - 1) cost: 4
// Minimum cost = 15