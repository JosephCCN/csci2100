typedef struct BinaryTreeCDT *BinaryTreeADT;
typedef struct TreeNodeCDT *TreeNodeADT;
#define specialErrNode (TreeNodeADT) NULL;

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT, BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree();
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
int TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
TreeNodeADT newNode(char*);
char *GetNodeKey(TreeNodeADT);
TreeNodeADT findNode(BinaryTreeADT, char*);
void insertNode(TreeNodeADT, BinaryTreeADT);
void deleteNode(TreeNodeADT, BinaryTreeADT);
