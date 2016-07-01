#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define SIZE 10
static int visited[10] = {0};
static count;

static void dfs_visit(int val[][SIZE],int v,int n)
{
    int i;
    count++;
    visited[v] = count;
    for(i = 0; i < n; i++) {
        if(val[i][v] == 1) {
            if( visited[i] == 0) {
                printf("%d ",i);
                dfs_visit(val,i,n);
            }
        }
    }
}
static void dfs( int matrix[][SIZE],int n)
{
    int i;
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs_visit(matrix,i,n);
        }
    }
}
int main()
{
    int i,j,n,val[size][size];
    printf("Hello, World!, we are running DFS now\n");
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&val[i][j]);
            
    printf("DFS begins\n");
    dfs(val,n);
    return 0;
}

