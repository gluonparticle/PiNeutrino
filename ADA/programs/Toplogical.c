#include<stdio.h>

void ts(int a[20][20], int n)
{
    int t[10], vis[10], stack[10], indeg[10], top = 0, ele, k = 1;

    for(int i = 1; i <= n; i++) 
    {
        t[i] = 0;
        vis[i] = 0;
        indeg[i] = 0;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            if(a[i][j]) 
                indeg[j]++;

    printf("Indegree Array: ");
    for(int i = 1; i <= n; i++) 
        printf("%d ", indeg[i]);

    for(int i = 1; i <= n; i++) 
        if(indeg[i] == 0) 
        {
            stack[++top] = i;
            vis[i] = 1;
        }

    while(top > 0)
    {
        ele = stack[top--];
        t[k++] = ele;
        
        for(int j = 1; j <= n; j++)
            if(a[ele][j] && !vis[j] && --indeg[j] == 0) 
            {
                stack[++top] = j;
                vis[j] = 1;
            }
    }

    printf("\nTopological Ordering is: ");
    for(int i = 1; i <= n; i++) 
        printf("%d ", t[i]);
}

int main()
{
    int n, a[20][20];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            scanf("%d", &a[i][j]);

    ts(a, n);
    return 0;
}
