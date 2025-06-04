#include <stdio.h>

#define MAX 50

int main() {
    int n, M, i;
    float weight[MAX], profit[MAX], ratio[MAX], total = 0;
    int index[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for (i = 0; i < n; i++) scanf("%f", &weight[i]);

    printf("Enter profits: ");
    for (i = 0; i < n; i++) scanf("%f", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &M);

    // 1. Compute profit/weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
        index[i] = i;
    }

    // 2. Sort items by ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                float temp = ratio[i]; 
                ratio[i] = ratio[j]; 
                ratio[j] = temp;


                int t2 = index[i]; 
                index[i] = index[j]; 
                index[j] = t2;
            }
        }
    }

    // 3. Greedy selection
    for (i = 0; i < n; i++) {
        int id = index[i];
        if (weight[id] <= M) {
            total += profit[id];
            M -= weight[id];
        } else {
            total += ratio[i] * M;
            break;
        }
    }

    printf("Maximum profit: %.2f\n", total);
    return 0;
}
