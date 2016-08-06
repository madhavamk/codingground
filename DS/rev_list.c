#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
typedef struct node * NODE;

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

NODE reverse(NODE first) {
    NODE temp = first, cur = NULL;
    
    while(first != NULL) {
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}

NODE insert(NODE first, int data) {
    NODE cur,temp;
    temp = getNode();
    if(!temp) {
        printf("\nERROR: Unable to allocate memory for the node\n");
        return first;
    }
    temp->data = data;
    /* if temp is the first node in the list */
    if(first == NULL) {
        temp->link = NULL;
        return temp;
    }
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = NULL;
    return first;
}

void display(NODE first) {
    NODE temp = first;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

int main() 
{
    int choice = 0;
    NODE first = NULL;
    int data;
    for(;;) {
        printf("\nEnter your option\n");
        printf("1.Insert 2.Distplay 3.Exit\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:printf("\nEnter data to the linked list\n");
                   scanf("%d",&data);
                   first = insert(first,data);
                   break;
            case 2:if (first == NULL) {
                       printf("\nList is empty\n");
                    } else {   
                       printf("\nList contents are\n");
                       display(first);
                    }
                   break;
            case 3:exit(0);
        }
    }
}