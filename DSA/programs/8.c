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

int main() {
    NODE *head = NULL;
    int ch;
    while (1) {
        printf("-------EMPLOYEE DATABASE SYSTEM ------");
        printf("\n1. Insert at Rear\t2. Display\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insertrear(head);
                display(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}
