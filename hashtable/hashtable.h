#include<stdbool.h>

struct Node{
        struct Node *next;
        char *key;
        int value;
};

typedef struct Node *node;

struct HashTB{
        node bucket[100];
};

typedef struct HashTB *HashTbADT;
typedef void (*func)(int, char*);

HashTbADT newHashTable();
void insert(HashTbADT, char*, int);
int find(HashTbADT, char*);
void del(HashTbADT, char*);
void forAllElement(func, HashTbADT);
