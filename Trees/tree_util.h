#ifndef __TREE_UTIL_H__
#define __TREE_UTIL_H__

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node* NODE;

typedef int bool;
NODE root;

NODE getNode();
void freeNode (NODE ptr);
NODE insert(NODE root, int data);
int max(int a, int b);
int height(NODE root);
void print(NODE root);
void print_pretty(NODE root, int spaces);
int diameter_tree(NODE root);
NODE lowest_common_ancestor(NODE root, int k1, int k2);
bool is_present(NODE root, int n);

#endif