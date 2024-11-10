#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int q[MAX];
int count = 0;
int front = 0;
int rear = -1;

void insert(int item, int *count, int *q, int *rear) {
    if (*count == MAX) {
        printf("\nCircular Queue is Full!");
    } else {
        *rear = (*rear + 1) % MAX;
        q[*rear] = item;
        (*count)++;
    }
}

void del(int *count, int *q, int *front) {
    if (*count == 0) {
        printf("\nCircular Queue is Empty!");
    } else {
        int itemdel = q[*front];
        *front = (*front + 1) % MAX;
        (*count)--;
        printf("\nItem Deleted: %d", itemdel);
    }
}

void display(int front, int count, int q[]) {
    if (count == 0) {
        printf("\nCircular Queue is Empty!");
    } else {
        printf("\nContents of Queue are:\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t", q[front]);
            front = (front + 1) % MAX;
        }
    }
}

int main() {
    int ch, item;

    while (1) {
        printf("\n1. Insert\t2. Delete\t3. Display\t4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter item to be inserted: ");
                scanf("%d", &item);
                insert(item, &count, q, &rear);
                break;
            case 2:
                del(&count, q, &front);
                break;
            case 3:
                display(front, count, q);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}
