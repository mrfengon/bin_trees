#ifndef TREE_H
#define TREE_H

typedef struct tree {
    char info;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} tree;

#endif