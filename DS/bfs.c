#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_SIZE 10
#define SIZE 10
static int visited[10] = {0};
static int count;
static int q[QUEUE_SIZE];
static int f = 0, r = -1;

static bool q_is_empty() {
    if(f == 0 && r == -1) {
        return true;
    } else {
        return false;
    }
}

static bool q_is_full() {
    if(r == QUEUE_SIZE - 1) {
        return true;
    } 
    return false; 
}

static int pop()
{
    int ele;
    if(!q_is_empty()) {
        ele = q[f++];
        if( f > r) {
            f = 0, r = -1;
        }
        printf("%d ",ele);
        return ele;
    }
    return -1;
}

static void q_insert(int element) {
    if(!q_is_full()) {
        q[++r] = element;
    }
}

static void bfs_visit(int val[][SIZE],int v,int n)
{
    int i;
    int j = 0;
    int front_v;
    q_insert(v);
    count++;
    visited[v] = count;
    while(!q_is_empty()) {
        front_v = pop();
        if(front_v == -1) {
            break;
        }
        for(i = 0; i < n; i++) {
            if(val[i][front_v] == 1) {
                if( visited[i] == 0) {
                    count++;
                    visited[i] = count;
                    q_insert(i);
                }
            }
        }
    }
}
static void bfs( int matrix[][SIZE],int n)
{
    int i;
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            bfs_visit(matrix,i,n);
        }
    }
}

int main()
{
    int i,j,n,val[SIZE][SIZE];
    printf("Hello, World!, we are running BFS now\n");
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&val[i][j]);
            
    printf("BFS begins\n");
    bfs(val,n);
    return 0;
}
