#include<stdio.h>
#include<string.h>
#include "BinaryTree.h"

int main(){
        BinaryTreeADT t = EmptyBinaryTree();
        t = insertNode(newNode("test", 1), t);
        t = insertNode(newNode("hi", 9), t);
        TreeNodeADT n = Root(t);
        printf("%d", GetNodeData(n));
}
