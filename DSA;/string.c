#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[50],pat[50],rep[50],ans[50];
int i,j,k,m,c,flag=0;
void stringmatch(){
    i=m=c=j=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!='\0';k++)
                ans[j++]=rep[k];
                c=m;
                i=0;
            }
        }
        else{
            ans[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
int main(){
    printf("\nEnter a Main String:\n");
    gets(str);
    printf("\nEnter a Patter String:\n");
    gets(pat);
    printf("\nEnter a Replacement String:\n");
    gets(rep);

    stringmatch();

    if(flag==1)
    printf("\nThe resultant string is :\n%s",ans);
    else
    printf("\nPattern String not found!!\n");

    return 0;
}