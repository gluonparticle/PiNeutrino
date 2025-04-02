#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) 
        R[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));
    int n = 10000, elements[n];
    for (int i = 0; i < n; i++) 
        elements[i] = rand() % 1000;

    int num;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &num);
    if (num <= 0 || num > n) {
        printf("Invalid input size. Enter between 1 and %d.\n", n);
        return 1;
    }

    int arr[num];
    printf("Enter %d numbers:\n", num);
    for (int i = 0; i < num; i++) 
        scanf("%d", &arr[i]);

    clock_t start = clock();
    mergeSort(arr, 0, num - 1);
    clock_t end = clock();
    
    printf("Sorted Array:\n");
    for (int i = 0; i < num; i++) 
        printf("%d ", arr[i]);
    printf("\nTime taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int size = 500; size <= n; size += 500) {
        int arr_temp[size];
        for (int i = 0; i < size; i++) 
            arr_temp[i] = elements[i];
        
        start = clock();
        mergeSort(arr_temp, 0, size - 1);
        end = clock();
        
        printf("Time for %d elements: %.6f seconds\n", size, (double)(end - start) / CLOCKS_PER_SEC);
    }
    return 0;
}
