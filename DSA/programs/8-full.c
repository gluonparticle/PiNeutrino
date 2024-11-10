#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int ssn;
    char name[15];
    char dept[10];
    char desig[20];
    int salary;
    char phno[15];
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

int countnodes(NODE *head) {
    NODE *temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

NODE* getnode() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("\nMemory allocation failed!!\n");
        return NULL;
    }
    newnode->prev = newnode->next = NULL;
    printf("Enter SSN: ");
    scanf("%d", &newnode->ssn);
    printf("Enter Name: ");
    scanf("%s", newnode->name);
    printf("Enter Department: ");
    scanf("%s", newnode->dept);
    printf("Enter Designation: ");
    scanf("%s", newnode->desig);
    printf("Enter Salary: ");
    scanf("%d", &newnode->salary);
    printf("Enter PhoneNo.: ");
    scanf("%s", newnode->phno);
    return newnode;
}

void display(NODE *head) {
    if (countnodes(head) == 0) {
        printf("Database Empty!!\n");
        return;
    }
    printf("SSN\tNAME\t\tDEPARTMENT\tDESIGNATION\tSALARY\tPHONENO\n");
    NODE *temp = head;
    while (temp) {
        printf("%d\t%s\t\t%s\t\t%s\t%d\t%s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->salary, temp->phno);
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", countnodes(head));
}

NODE* insertrear(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("Database Full!!\n");
        return head;
    }
    NODE *newnode = getnode();
    if (head == NULL) {
        return newnode;
    }
    NODE *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

NODE* insertfront(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("Database Full!!\n");
        return head;
    }
    NODE *newnode = getnode();
    if (head == NULL) {
        return newnode;
    }
    newnode->next = head;
    head->prev = newnode;
    return newnode;
}

NODE* insert(NODE *head) {
    int ch = 0;
    while (ch != 3) {
        printf("1. Insert Front\t2. Insert Rear\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insertfront(head);
                display(head);
                break;
            case 2:
                head = insertrear(head);
                display(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }
    return head;
}

NODE* del_rear(NODE *head) {
    if (head == NULL) {
        printf("Database empty!\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        printf("Data Deleted!\n");
        return NULL;
    }
    NODE *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Data Deleted!\n");
    return head;
}

NODE* del_front(NODE *head) {
    if (head == NULL) {
        printf("Database Empty\n");
        return head;
    }
    NODE *temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    free(temp);
    printf("Data Deleted!\n");
    return head;
}

NODE* del(NODE *head) {
    int ch = 0;
    while (ch != 3) {
        printf("1. Delete Front\t2. Delete Rear\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = del_front(head);
                display(head);
                break;
            case 2:
                head = del_rear(head);
                display(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }
    return head;
}

NODE* dqueue(NODE *head) {
    int ch;
    while (1) {
        printf("\nDLL used as Double Ended Queue");
        printf("\n1. Insert at Rear\n2. Delete from Front\n3. Insert at Front\n4. Delete from Rear\n5. Display\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insertrear(head);
                display(head);
                break;
            case 2:
                head = del_front(head);
                display(head);
                break;
            case 3:
                head = insertfront(head);
                display(head);
                break;
            case 4:
                head = del_rear(head);
                display(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                return head;
            default:
                printf("Invalid choice!!\n");
        }
    }
}

NODE* create(NODE *head) {
    if (head == NULL) {
        head = getnode();
    } else {
        head = insertfront(head);
    }
    return head;
}

int main() {
    NODE *head = NULL;
    int ch, n;
    while (1) {
        printf("-------EMPLOYEE DATABASE SYSTEM ------");
        printf("\n1. Create\t2. Display\t3. Insert\t4. Delete\t5. Queue\t6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("How many records you want to create? : ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nEnter Employee %d Details:--\n", i + 1);
                    head = create(head);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insert(head);
                break;
            case 4:
                head = del(head);
                break;
            case 5:
                head = dqueue(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}
