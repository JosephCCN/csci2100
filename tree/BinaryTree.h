typedef struct BinaryTreeCDT *BinaryTreeADT;
typedef struct TreeNodeCDT *TreeNodeADT;
#define specialErrNode (TreeNodeADT) NULL;

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT, BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree();
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
int TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
TreeNodeADT newNode(char*, int);
char *GetNodeKey(TreeNodeADT);
int GetNodeData(TreeNodeADT);
TreeNodeADT findNode(BinaryTreeADT, char*);
BinaryTreeADT insertNode(TreeNodeADT, BinaryTreeADT);
BinaryTreeADT deleteNode(TreeNodeADT, BinaryTreeADT);
int TreeNodeIsEmpty(TreeNodeADT);
BinaryTreeADT nodeToTree(TreeNodeADT);
