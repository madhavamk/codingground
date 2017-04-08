#include <stdio.h>
#include <stdlib.h>
#include "tree_util.h"

int main()
{
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
