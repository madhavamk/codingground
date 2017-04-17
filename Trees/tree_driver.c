#include <stdio.h>
#include <stdlib.h>
#include "tree_util.h"

int main()
{
    int choice,item,n1,n2;
    for (;;)
    {
        printf("\nEnter your choice\n");
        printf("1. Insert   2.Display 3. Diameter_tree 4.Pretty Print 5:LCA\n");
        printf("6:Exit\n");
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
                printf("\nDiameter of tree is %d\n",diameter_tree(root));
                break;
            case 4:
                if (root == NULL) {
                    printf("\nTree is empty\n");
                } else {
                    printf("Tree contents are\n");
                    print_pretty(root, 0);
                    printf("\n");
                }
                break;
            case 5:
                if (root != NULL) {
                    printf("\nTree contenrs are\n");
                    print_pretty(root,0);
                    printf("\nEnter two nodes for which you need to find LCA\n");
                    scanf("%d%d",&n1,&n2);
                    if (is_present(root,n1) && is_present(root,n2)) {
                        printf("LCA of %d and %d is %d\n",n1,n2,lowest_common_ancestor(root,n1,n2)->data);
                    } else {
                        printf("\nOne of the entered nodes not present in Tree, give proper inputs\n");
                    }
                }
                else {
                    printf("\nTree is empty\n");
                }
                break;
            default:
                exit(0);
        }
    }
}
