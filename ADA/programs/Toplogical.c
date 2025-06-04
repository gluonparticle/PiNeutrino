#include<stdio.h>
void ts(int a[20][20], int n)
{
    int t[10],vis[10],stack[10],i,j,indeg[10],top=0,ele,k=1;
    for(i=1;i<=n;i++)
    {
        t[i]=0;
        vis[i]=0;
        indeg[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                indeg[j]=indeg[j]+1;
            }
        }
    }
    printf("Indegree Array:");
    for(i=1;i<=n;i++)
        printf("%d ",indeg[i]);
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            stack[++top]=i;
            vis[i]=1;
        }
    }
    while(top>0)
    {
        ele=stack[top--];
        t[k++]=ele;
        for(j=1;j<=n;j++)
        {
            if(a[ele][j]==1 && vis[j]==0)
            {
                indeg[j]=indeg[j]-1;
                if(indeg[j]==0)
                {
                    stack[++top]=j;
                    vis[j]=1;
                }

            }
        }
    }
    printf("\nTopological Ordering is:");
    for(i=1;i<=n;i++)
        printf("%d",t[i]);
}
int main()
{
    int n,a[20][20],i,j;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter Adjacency matric\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    ts(a,n);
}
