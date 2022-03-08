#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "BinaryTree.h"

struct TreeNodeCDT{
        char* key;
        int nodeData;
};

struct BinaryTreeCDT{
       struct TreeNodeCDT *node;
       struct BinaryTreeCDT *left, *right;
};

TreeNodeADT newNode(char* str, int value){
    TreeNodeADT t = (TreeNodeADT)malloc(sizeof(*t));
    t->key = (char*)malloc(sizeof(char)*(strlen(str) + 1));
    strcpy(t->key , str);
    t->nodeData = value;
    return t;
}


BinaryTreeADT EmptyBinaryTree(){
        return (BinaryTreeADT) NULL;
}

int TreeIsEmpty(BinaryTreeADT t){
        return t == (BinaryTreeADT)NULL;
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
        TreeNodeADT r = newNode(t->node->key, t->node->nodeData);
        return r;
}

int TreeNodeIsEmpty(TreeNodeADT t) {
        return t == (TreeNodeADT)NULL;
}

char *GetNodeKey(TreeNodeADT t) {
        if(t == NULL) exit(EXIT_FAILURE);
        char* str = (char*)malloc(sizeof(char) * (strlen(t->key) + 1));
        strcpy(str, t->key);
        return str;
}

int GetNodeData(TreeNodeADT t) {
        if(t == NULL) exit(EXIT_FAILURE);
        return t->nodeData;
}

BinaryTreeADT nodeToTree(TreeNodeADT node) {
        BinaryTreeADT tree = (BinaryTreeADT)malloc(sizeof(*tree));
        tree->node = node;
        tree->left = tree->right = NULL;
        return tree;
}

BinaryTreeADT insertNode(TreeNodeADT node, BinaryTreeADT tree){
        if(TreeIsEmpty(tree)) tree = nodeToTree(node);
        else if(strcmp(node->key, tree->node->key) > 0) tree->right = insertNode(node, tree->right);
        else tree->left = insertNode(node, tree->left);
        return tree;
}

TreeNodeADT findNode(BinaryTreeADT tree, char* key) {
        if(TreeIsEmpty(tree)) return specialErrNode;
        int s = strcmp(tree->node->key, key);
        if(s == 0) return tree->node;
        if(s < 0) return findNode(tree->left, key);
        else return findNode(tree->right, key);
}

BinaryTreeADT deleteNode(TreeNodeADT node, BinaryTreeADT tree) {

}
