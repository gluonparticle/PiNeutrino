#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int* a, int* b);

void quicksort(int a[], int low, int high){
    if (low < high){
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int  pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

int main() {
    srand(time(NULL));
    int n = 100000;
    int elements[n];

    for (int i = 0; i < n; i++)    
        elements[i] = rand() % 1000;


    for (int size = 5000; size <= n; size += 2000) { {
        int arr[size];
        
        for (int i = 0; i < size; i++){
            arr[i] = elements[i];
        }

        clock_t start = clock();        
        quicksort(arr, 0, size - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;        
        printf("Total time taken to sort %d elements is %lf seconds\n", size, time_taken);
    }

    return 0;
}
