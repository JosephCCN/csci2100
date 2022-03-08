#include<stdio.h>
#include<string.h>
#include "BinaryTree.h"

int main(){
        BinaryTreeADT t = EmptyBinaryTree();
        t = insertNode(newNode("test", 1), t);
        t = insertNode(newNode("hi", 4) ,t);
        TreeNodeADT n = findNode(t, "hi");
        printf("%d", GetNodeData(n));
}
