#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int A[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(A[j] < A[min]) min = j;
        }
        if(min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 30000;
    int elements[n];
    for(int i = 0; i < n; i++) elements[i] = rand() % 1000;

    for(int size = 5000; size <= n; size += 2000) {
        int arr[size];
        for(int i = 0; i < size; i++) arr[i] = elements[i];
        
        clock_t start = clock();
        selectionsort(arr, size);
        clock_t stop = clock();
        
        printf("Time taken to sort %d elements is %f seconds\n", size, (double)(stop - start) / CLOCKS_PER_SEC);
    }
    return 0;
}
