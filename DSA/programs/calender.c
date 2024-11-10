#include<stdio.h>
#include<stdlib.h>

struct day {
  char *dayname;
  int date;
  char *activity;
};
typedef struct day DAY;

void create(DAY *day){
  day->dayname = (char*)malloc(20 * sizeof(char));
  day->activity = (char*)malloc(50 * sizeof(char));
  printf("\nEnter Dayname, Date, Activity:\n");
  scanf("%s%d%s", day->dayname, &day->date, day->activity);
}

void read(DAY *day, int size){
  for(int i = 0; i < size; i++){
    printf("Enter the details for the %d day", i + 1);
    create(&day[i]);
  }
}

void freememory(DAY *day, int size){
  for(int i = 0; i < size; i++){
    free(day[i].dayname);
    free(day[i].activity);
  }
}

void display(DAY *day, int size){
  printf("\nActivity Details");
  printf("\n___________________________________________________");
  printf("\nDay\t\tName of the day\tDate\tActivity\n");
  printf("\n___________________________________________________");

  for(int i = 0; i < size; i++){
    printf("\n%d\t\t%s\t\t%d\t\t%s\n", i + 1, day[i].dayname, day[i].date, day[i].activity);
  }
}

int main(){
  int n;
  printf("Enter the number of days in the week:");
  scanf("%d", &n);

  DAY *calender;
  calender = (DAY*)malloc(n * sizeof(DAY));
  if(calender == NULL){
    printf("Memory Allocation Failed!!");
    return 1;
  }

  read(calender, n);
  display(calender, n);
  freememory(calender, n);
  free(calender);

  return 0;
}