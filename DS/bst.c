#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node* NODE;

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

NODE freeNode (NODE p)
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

int main()
{
    NODE root = NULL;
    int choice,item;
    for (;;)
    {
        printf("\nEnter your choice\n");
        printf("1. Insert   2.Display 3.Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("\nEnter the item to be inserted\n");
                scanf("%d",&item);
                root = insert(root,item);
                break;
            case 2:
                if (root == NULL) {
                    printf("\nTree is empty\n");
                } else {
                    printf("Tree contents are\n");
                    print(root);
                    printf("\n");
                }
                break;
            case 3:
                exit(0);
        }
    }
}

