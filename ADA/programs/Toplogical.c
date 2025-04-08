#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[low], &arr[j]);
    return j;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand(time(NULL));
    int n = 100000;
    int elements[n];
    for (int i = 0; i < n; i++) {
        elements[i] = rand() % 1000;
    }
    for (int size = 5000; size <= n; size += 5000) {
        int arr[size];
        for (int i = 0; i < size; i++) {
            arr[i] = elements[i];
        }
        clock_t start = clock();
        quicksort(arr, 0, size - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %lf seconds\n", size, time_taken);
    }
    return 0;
}
