#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct cellT {stackElement value; struct cellT *above;} cellT;

struct stackCDT {
        cellT *bottom;
        cellT *top;
        int cnt;
};


int stackdepth(stackADT this){
        return this->cnt;
}

stackADT emptystack() {
        stackADT stack;
        stack = (stackADT)malloc(sizeof(*stack));
        stack->cnt = 0;
        stack->bottom = (cellT*)malloc(sizeof(cellT*));
        stack->bottom = NULL;
        stack->top = (cellT*)malloc(sizeof(cellT*));
        stack->top = NULL;
        return stack;
}

int stackisempty(stackADT this) {
        return 0 == this->cnt;
}

void pop(stackADT this) {
        if(stackisempty(this)) exit(EXIT_FAILURE);
        if(stackdepth(this) == 1) {
                free(this->top);
                this->top = NULL;
                this->bottom = NULL;
                this->cnt = 0;
                return;
        }
        cellT *cell = this->bottom;
        while(cell->above->above != NULL) cell = cell->above;
        free(cell->above);
        cell->above = NULL;
        this->top = cell;
        this->cnt--;
}


void push(stackADT this, int n) {
        cellT *cell;
        cell = (cellT*)malloc(sizeof(cellT*));
        cell->value = n;
        cell->above = NULL;
        this->top->above = cell;
        this->top = cell;
        if(stackisempty(this)) this->bottom = cell;
        this->cnt++:
}
