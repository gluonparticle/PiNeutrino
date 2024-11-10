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

int countnodes(NODE *head) {
    NODE *p = head;
    int count = 0;
    while (p != NULL) {
        p =

    p=p->next;
    count++;
  }
  return count;
}

NODE* getnode(){
  NODE *newnode;
  newnode = (NODE*)malloc(sizeof(NODE));
  newnode->next=NULL;
  if(newnode==NULL){
    printf("Memory allocation failed!!");
    return 0;
  }
  else{
    printf("Enter USN:");
    scanf("%s",newnode->usn);
    printf("Enter Name:");
    scanf("%s",newnode->name);
    printf("Enter Branch:");
    scanf("%s",newnode->branch);
    printf("Enter Sem:");
    scanf("%d",&newnode->sem);
    printf("Enter Phone No:");
    scanf("%s",newnode->phone);
  }
  return newnode;
}


NODE* display(NODE* head){   
  NODE *p;
  if(head==NULL){
    printf("No Student Details to Display !!\n");
    return head;
  }
  else{
    printf("\nUSN\t\tNAME\t\tBRANCH\t\tSEM\t\tPHONE NO.\n");
    p=head;
    while(p!=NULL){
      printf("%s\t%s\t\t%s\t\t%d\t\t%s\n",p->usn,p->name,p->branch,p->sem,p->phone);
      p=p->next;
    }
  }
  printf("\nThe number of nodes in the list is : %d",countnodes(head));
  return head;
}

NODE* insert_front(NODE *head){
  if(max == countnodes(head)){
    printf("Database Full !!\n");
    return head;
  }
  NODE *newnode;
  newnode = getnode();
  newnode->next = head;
  return newnode;
}

NODE* insert_rear(NODE *head){
  if(max == countnodes(head)){
    printf("Database Full !!\n");
    return head;
  }
  NODE *temp , *newnode;
  temp = head;
  newnode = getnode();
  if(head==NULL){
    return newnode;
  }
  else{
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newnode;
    return head;
  }
}

NODE* del_front(NODE *head){
  if(countnodes(head)==0){
    printf("Database Empty !!\n");
    return head;
  }
  NODE *temp;
  temp = head;
  head = head->next;
  free(temp);
  printf("Data Deleted!!\n");
  return head;
}

NODE* del_rear(NODE *head) {
    if (head == NULL) {
        printf("\nDatabase Empty !!\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        printf("Data Deleted!!\n");
        return NULL;
    }
    NODE *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Data Deleted!!\n");
    return head;
}


NODE* del(NODE *head){
  int ch;
  while (ch!=3) {
    printf("1.del_front\t2.del_rear\t3.Exit\nEnter your choice:\t");
    scanf("%d",&ch);
    switch(ch){
      case 1 :head = del_front(head);
              head = display(head);
              break;
      case 2 :head = del_rear(head);
              head = display(head);
              break;
      case 3 :break;
    }
  }
  return head;
}

NODE* insert(NODE *head){
  int ch;
  while (ch!=3) {
    printf("1.insert_front\t2.insert_rear\t3.Exit\nEnter your choice:\t");
    scanf("%d",&ch);
    switch(ch){
      case 1 :head = insert_front(head);
              head = display(head);
              break;
      case 2 :head = insert_rear(head);
              head = display(head);
              break;
      case 3 :break;
    }
  }
  return head;
}

NODE* stack(NODE *head){
  int ch;
  do{
    printf("\nSSL used as Stack...");
    printf("\n 1.Insert at Front(PUSH) \t 2.Delete from Front(POP))\t3.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1: head=insert_front(head);
              head = display(head);
              break;
      case 2: head=del_front(head);
              head = display(head);
              break;
      case 3: break;
    }
  }while(ch!=3);
  return head;
}

NODE* create(NODE *head){
  NODE *newnode;
  if(head==NULL){
    newnode=getnode();
    head=newnode;
  }
  else{
    head = insert_front(head);
  }
  return  head;
}

int main(){
int ch, i, n;
NODE *head;
head=NULL;
printf("\n*----------StudentDatabase-----------*");
do{
  printf("\n 1.Create\t 2.Display\t 3.Insert\t 4.Delete\t 5.Stack\t 6.Exit");
  printf("\nEnter your choice: ");
  scanf("%d", &ch);
  switch(ch){
    case 1: printf("\nHow many student data you want to create: ");
            scanf("%d", &n);
            for(i=0;i<n;i++){
              printf("Enter Student%d Details:--\n",i+1);
              head = create(head);
            }
            break;
    case 2: head=display(head);
            break;
    case 3: head=insert(head);
            break;
    case 4: head=del(head);
            break;
    case 5: head=stack(head);
            break;
    case 6: break;
  }
}while(ch!=6);
return 0;
}
