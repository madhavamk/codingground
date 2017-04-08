#include <stdio.h>
#include <stdlib.h>
#include "tree_util.h"

NODE getNode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if ( temp == NULL ) {
        printf("\nUnable to allocate memory\n");
        return NULL;
    }
    return temp;
}

void freeNode (NODE p)
{
    if (p) {
        free(p);
        p = NULL;
    }
}

NODE insert(NODE root, int data)
{
    NODE temp = getNode();
    NODE cur,prev;
    if (temp == NULL) {
        printf("\nNo memory available to insert node\n");
        return root;
    }
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
        
    /* If the node is the first node */
    if (root == NULL) {
        return temp;
    }
    
    /* Insert at appropriate position in left subtree*/
    prev = NULL;
    cur = root;
    while (cur != NULL) {
        prev = cur;
        if(data < cur->data) {
            cur = cur->lchild;
        } else {
            cur = cur->rchild;
        }
    }
    if (data < prev->data) {
        prev->lchild = temp;
    } else {
        prev->rchild = temp;
    }
    return root;
}

void print(NODE root)
{
    if(root == NULL) {
        return;
    }
    print(root->lchild);
    printf("%d ",root->data);
    print(root->rchild);
}

int max(int a, int b)
{
    return a >= b ? a: b;
}

int height(NODE root)
{
    if( root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->lchild),height(root->rchild));
}

int diameter_tree(NODE root)
{
    int lheight, rheight,ldiameter,rdiameter;
    if( root == NULL) {
        return 0;
    }
    lheight = height(root->lchild);
    rheight = height(root->rchild);
    
    ldiameter = diameter_tree(root->lchild);
    rdiameter = diameter_tree(root->rchild);
    
    return max(lheight+rheight+1, max(ldiameter,rdiameter));
}

void print_pretty(NODE root, int spaces)
{
    int i;
    if( root != NULL) {
        print_pretty(root->rchild, spaces + 4);
        for(i = 0; i < spaces; i++) {
            printf(" ");
        }
        printf("%d\n",root->data);
        print_pretty(root->lchild, spaces + 4);
    }
}
