#include<stdio.h>
#include<stdlib.h>
#define max 4
int stack[max],i,itemdel;
int top = -1;
int flag=1;
int status = 0;

void push(int stack[] , int item){
  if(top==max-1){
    printf("\nStack is Full!");
  }
  else{
    stack[++top] = item ;
    status++;
  }
}

void pop(int stack[]){
  if(top==-1){
    printf("\nStack is Empty!");
  }
  else{
    itemdel = stack[top--];
    status--;
    printf("\nItem deleted = %d",itemdel);
  }
}

void display(int stack[]){
  if(top==-1){
    printf("\nStack is Empty!");
  }
  printf("\nStack contents are :\n");
  for(i=top;i>=0;i--){
    printf("|%d|\n",stack[i]);
  }
}

void pallindrome(int stack[]){
  display(stack);
  printf("\nReverse of stack contents are:\n");
  for(i=0;i<=top;i++){
    printf("|%d|\n",stack[i]);
  }

  for(i=0;i<=top/2;i++){
    if(stack[i]!=stack[top-i])
    flag=0;
    break;
  }
  if(flag==1)
  printf("\nStack is a Pallindrome.");
  else
  printf("\nStack is Not a Pallinrome.");
}

int main(){
  int ch,item;
  while(ch!=5){
    printf("\n1.Push\t2.Pop\t3.Display\t4.Pallindrome\t5.Exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1:
      printf("\nEnter the element to be inserted:");
      scanf("%d",&item);
      push(stack,item);
      break;
      case 2:
      pop(stack);
      break;
      case 3:
      display(stack);
      break;
      case 4:
      pallindrome(stack);
      break;
      case 5:
      break;
      default :
      printf("\nInvalid Choice!!");
    }
  }
  return 0;
}