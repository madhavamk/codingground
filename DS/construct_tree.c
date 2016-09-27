#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node* NODE;

NODE getNode( int data)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if ( temp == NULL ) {
        printf("\nUnable to allocate memory\n");
        return NULL;
    }
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

int search( int in[], int start, int end, int data) 
{
    int i;
    for( i = start; i <= end; i++)
    {
        if(in[i] == data) {
            break;
        }
        return i;
    }
}
NODE buildTree(int in[], int post[], int iStrt, int iEnd, int *pIndex)
{
    int index;
    Node node;
    if( iStrt > iEnd) {
        return NULL;
    }
    
    node = getNode(post[*pIndex]);
    *pIndex--;
    
    if( iStrt == iEnd) {
        return node;
    }
    
    index = search(in, iStrt, iEnd, node->data);
    node->rchild = buildTree(in, post, index+1, iEnd, &pIndex);
    node->lchild = buildTree(in, post, iStrt, index - 1, &pIndex);
    return node;
}

NODE build( int in[], int post[], int n)
{
    int pIndex = n-1;
    NODE root = buildTree(in,post,0,n-1,&pIndex);
}
int main()
{
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);
 
    NODE root = build(in, post, n);
 
    return 0;
}