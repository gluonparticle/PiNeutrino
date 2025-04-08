#include<stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyds(int p[10][10], int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int main() {
    int p[10][10], n, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nMatrix of input data (999 for infinity):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &p[i][j]);
            if(p[i][j] == 0)
                p[i][j] = 999;
        }
    }

    floyds(p, n);

    printf("\nThe shortest paths are:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i != j)
                printf("<%d,%d> = %d\n", i, j, p[i][j]);
        }
    }

    return 0;
}
