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
