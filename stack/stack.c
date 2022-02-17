#include "stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


void resize(stackADT this, int s) {
        this->size = s;
        this->elem = (int*)realloc(this->elem, s * sizeof(int));
}

int size(stackADT this){
        return this->cnt;
}

stackADT emptystack(int s) {
        stackADT stack;
        stack = (stackADT)malloc(sizeof(*stack));
        stack->size = s;
        stack->cnt = 0;
        stack->elem = (int*)malloc(s * sizeof(int));
        return stack;
}

bool isempty(stackADT this) {
        return 0 == this->cnt;
}

void pop(stackADT this) {
        if(isempty(this)) exit(1);
        this->cnt--;
}

void printstack(stackADT this) {
        for(int i=0;i<this->cnt;i++) printf("%d\n", this->elem[i]);
}

int top(stackADT this) {
        if(isempty(this)) exit(1);
        return this->elem[this->cnt - 1];
}

void push(stackADT this, int n) {
        if(this->size == this->cnt) resize(this, this->size * 2);
        this->elem[this->cnt++] = n;
}
