typedef int stackElement;
typedef struct stackCDT *stackADT;

int stackdepth(stackADT);
void pop(stackADT);
void push(stackADT, int);
stackADT emptystack(int);
int stackisempty(stackADT);
