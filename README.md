# Parallel Computing Lab - Offline Windows Setup

Run this script in **PowerShell (Run as Administrator)**. It creates all 9 program files directly across your target directories with zero network dependencies.

```powershell
$targets = @(
    "C:\Drivers\storage\NFT50\jdk11",
    "C:\Program Files\Oracle\jdk11",
    "C:\Program Files\Java\jdk18"
)

foreach ($t in $targets) {
    New-Item -ItemType Directory -Force -Path $t | Out-Null
}

$files = @{
"1.c" = @'
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 100000

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSortSeq(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortSeq(arr, l, m);
        mergeSortSeq(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortParallel(int arr[], int l, int r) {
    if (r - l < SIZE) {
        mergeSortSeq(arr, l, r);
    } else if (l < r) {
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortParallel(arr, l, m);
            #pragma omp section
            mergeSortParallel(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100000;
}

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

int main() {
    int *a1 = (int *)malloc(SIZE * sizeof(int));
    int *a2 = (int *)malloc(SIZE * sizeof(int));
    double start, end;
    fillArray(a1, SIZE);
    copyArray(a1, a2, SIZE);
    start = omp_get_wtime();
    mergeSortSeq(a1, 0, SIZE - 1);
    end = omp_get_wtime();
    printf("Sequential Merge Sort Time: %.6f seconds\n", end - start);
    start = omp_get_wtime();
    mergeSortParallel(a2, 0, SIZE - 1);
    end = omp_get_wtime();
    printf("Parallel Merge Sort Time: %.6f seconds\n", end - start);
    free(a1);
    free(a2);
    return 0;
}
'@

"2.c" = @'
#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    printf("Enter number of iterations: ");
    scanf("%d", &n);
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        printf("Thread %d : Iteration %d\n", tid, i);
    }
    return 0;
}
'@

"3.c" = @'
#include <stdio.h>
#include <omp.h>

int fib_task(int n) {
    int x, y;
    if (n < 2)
        return n;
    #pragma omp task shared(x)
    x = fib_task(n - 1);
    #pragma omp task shared(y)
    y = fib_task(n - 2);
    #pragma omp taskwait
    return x + y;
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);
    printf("Fibonacci series:\n");
    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < n; i++) {
                int result = fib_task(i);
                printf("fib(%d) = %d\n", i, result);
            }
        }
    }
    return 0;
}
'@

"4.c" = @'
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int is_prime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    double start_time, end_time;
    start_time = omp_get_wtime();
    int serial_count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) serial_count++;
    }
    end_time = omp_get_wtime();
    printf("Serial Execution Time: %f seconds\n", end_time - start_time);
    omp_set_num_threads(4);
    int* prime_flags = (int*)calloc(n + 1, sizeof(int));
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 100)
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            prime_flags[i] = 1;
        }
    }
    end_time = omp_get_wtime();
    int parallel_count = 0;
    for (int i = 2; i <= n; i++) {
        if (prime_flags[i]) parallel_count++;
    }
    printf("Parallel Execution Time: %f seconds\n", end_time - start_time);
    printf("Primes found (Serial): %d, (Parallel): %d\n", serial_count, parallel_count);
    free(prime_flags);
    return 0;
}
'@

"5.c" = @'
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            char message[100];
            sprintf(message, "Hello from process 0 to process %d", i);
            MPI_Send(message, strlen(message) + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            printf("Process 0 sent message to process %d\n", i);
        }
    } else {
        char recv_buf[100];
        MPI_Recv(recv_buf, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process %d received message: %s\n", rank, recv_buf);
    }
    MPI_Finalize();
    return 0;
}
'@

"6.c" = @'
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int send_data, recv_data;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        send_data = 100;
        MPI_Send(&send_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&recv_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 0 received %d\n", recv_data);
    } else if (rank == 1) {
        send_data = 200;
        MPI_Send(&send_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received %d\n", recv_data);
    }
    MPI_Finalize();
    return 0;
}
'@

"7.c" = @'
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        number = 42;
        printf("Process 0 is broadcasting number %d\n", number);
    }
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, number);
    MPI_Finalize();
    return 0;
}
'@

"8.c" = @'
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int data[100];
    int recv_value;
    int gathered[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            data[i] = i * 10;
        }
        printf("Process 0 initialized data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
    MPI_Scatter(data, 1, MPI_INT, &recv_value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received value %d from Scatter\n", rank, recv_value);
    recv_value += rank;
    MPI_Gather(&recv_value, 1, MPI_INT, gathered, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Process 0 gathered data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", gathered[i]);
        }
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
'@

"9.c" = @'
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int value;
    int sum_result, prod_result, max_result, min_result;
    int all_sum, all_prod, all_max, all_min;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    value = rank + 1;
    printf("Process %d has value %d\n", rank, value);
    MPI_Reduce(&value, &sum_result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &prod_result, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &max_result, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &min_result, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("\n--- Results using MPI_Reduce (only on root) ---\n");
        printf("Sum = %d\n", sum_result);
        printf("Prod = %d\n", prod_result);
        printf("Max = %d\n", max_result);
        printf("Min = %d\n", min_result);
    }
    MPI_Allreduce(&value, &all_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    printf("Process %d - AllReduce: Sum=%d Prod=%d Max=%d Min=%d\n",
        rank, all_sum, all_prod, all_max, all_min);
    MPI_Finalize();
    return 0;
}
'@
}

foreach ($target in $targets) {
    foreach ($fileName in $files.Keys) {
        $filePath = Join-Path $target $fileName
        Set-Content -Path $filePath -Value $files[$fileName] -Encoding UTF8 -Force
    }
}

for ($i = 0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}
Clear-History

Write-Output "DONE: All 9 programs written to target directories."
```
