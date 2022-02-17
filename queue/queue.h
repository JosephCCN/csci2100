#include<stdbool.h>

struct CELL{
        int elem;
        struct CELL *next;
};

typedef struct CELL cell;

struct queueCDT{
        cell *front, *back;
        int sz;
};

typedef struct queueCDT *queueADT;

int size(queueADT);
queueADT newqueue();
void push(queueADT, int);
void pop(queueADT);
int front(queueADT);
bool isempty(queueADT);


