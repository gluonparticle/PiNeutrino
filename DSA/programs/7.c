#include <stdio.h>
#include <stdlib.h>

#define max 5

struct node {
    char usn[11];
    char name[15];
    char branch[5];
    int sem;
    char phone[15];
    struct node *next;
};

typedef struct node NODE;

NODE* getnode() {
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->next = NULL;
    if (newnode == NULL) {
        printf("Memory allocation failed!!");
        return NULL;
    } else {
        printf("Enter USN:");
        scanf("%s", newnode->usn);
        printf("Enter Name:");
        scanf("%s", newnode->name);
        printf("Enter Branch:");
        scanf("%s", newnode->branch);
        printf("Enter Sem:");
        scanf("%d", &newnode->sem);
        printf("Enter Phone No:");
        scanf("%s", newnode->phone);
    }
    return newnode;
}

NODE* display(NODE* head) {
    NODE *p;
    if (head == NULL) {
        printf("No Student Details to Display !!\n");
        return head;
    } else {
        printf("\nUSN\t\tNAME\t\tBRANCH\t\tSEM\t\tPHONE NO.\n");
        p = head;
        while (p != NULL) {
            printf("%s\t%s\t\t%s\t\t%d\t\t%s\n", p->usn, p->name, p->branch, p->sem, p->phone);
            p = p->next;
        }
    }
    return head;
}

int main() {
    int ch, n, i;
    NODE *head = NULL;
    printf("\n*----------StudentDatabase-----------*");
    do {
        printf("\n 1.Create\t 2.Display\t 3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nHow many student data you want to create: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter Student%d Details:--\n", i + 1);
                    NODE *newnode = getnode();
                    newnode->next = head;
                    head = newnode;
                }
                break;
            case 2:
                head = display(head);
                break;
            case 3:
                break;
        }
    } while (ch != 3);
    return 0;
}
