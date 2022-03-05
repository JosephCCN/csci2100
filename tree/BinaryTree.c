#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "BinaryTree.h"

struct TreeNodeCDT{
        char* key;
};

struct BinaryTreeCDT{
       struct TreeNodeCDT *node;
       struct BinaryTreeCDT *left, *right;
};

TreeNodeADT newNode(char* str){
    TreeNodeADT t = (TreeNodeADT)malloc(sizeof(*t));
    strcpy(t->key, str);
    return t;
}

BinaryTreeADT EmptyBinaryTree(){
    BinaryTreeADT t = (BinaryTreeADT)malloc(sizeof(*t));
    t->node = NULL;
    t->left = NULL;
    t->right = NULL;
    return t;
}

int TreeIsEmpty(BinaryTreeADT t){
        return t->node == NULL;
}

BinaryTreeADT LeftSubtree(BinaryTreeADT t) {
        if(TreeIsEmpty(t) || TreeIsEmpty(t->left)) exit(EXIT_FAILURE);
        return t->left;
}

BinaryTreeADT RightSubtree(BinaryTreeADT t) {
        if(TreeIsEmpty(t) || TreeIsEmpty(t->right)) exit(EXIT_FAILURE);
        return t->right;
}

TreeNodeADT Root(BinaryTreeADT t) {
        if(TreeIsEmpty(t)) exit(EXIT_FAILURE);
        return t->node;
}

char *GetNodeKey(TreeNodeADT t) {
        if(t == NULL) exit(EXIT_FAILURE);
        return t->key;
}
