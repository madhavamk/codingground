#ifndef __TREE_UTIL_H__
#define __TREE_UTIL_H__

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node* NODE;

NODE root;

NODE getNode();
void freeNode (NODE ptr);
NODE insert(NODE root, int data);
int max(int a, int b);
int height(NODE root);
void print(NODE root);
int diameter_tree(NODE root);

#endif