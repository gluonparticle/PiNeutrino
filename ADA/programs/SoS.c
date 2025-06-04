#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Function to find all subsets whose sum equals the target
void findSubsets(int items[], int numItems, int target, int currentSum, int currentIndex, int subset[], int subsetSize) {
    if (currentSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return; // Subset found, no need to explore further
    }

    if (currentSum > target || currentIndex >= numItems) {
        return; // Current subset sum exceeds target or no more items
    }

    // Include the current item in the subset
    subset[subsetSize] = items[currentIndex];
    findSubsets(items, numItems, target, currentSum + items[currentIndex], currentIndex + 1, subset, subsetSize + 1);

    // Exclude the current item from the subset
    findSubsets(items, numItems, target, currentSum, currentIndex + 1, subset, subsetSize);
}

int main() {
    int items[MAX_ITEMS];
    int numItems;
    int target;
    int subset[MAX_ITEMS];

    // Get input from the user
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the items (profits/values): ");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Find and print all subsets
    printf("Subsets with sum %d:\n", target);
    findSubsets(items, numItems, target, 0, 0, subset, 0);

    return 0;
}