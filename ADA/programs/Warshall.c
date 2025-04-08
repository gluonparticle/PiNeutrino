#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void warshal(int p[10][10], int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
            }
        }
    }
}

int main() {
    int p[10][10], n, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    warshal(p, n);

    printf("\nThe transitive closure is:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}
