#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int i, j, k, a, b, u, v, n, ne = 1;
int mincost = 0, cost[9][9], parent[9];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("\nKruskal's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;  
        }
    }

    printf("Cost Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }  
    printf("\n"); 
    

    printf("Edges in the Minimum Cost Spanning Tree:\n");
    while (ne < n) {
        int min = INF;

        // Find the edge with the smallest cost
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;  // Mark edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
