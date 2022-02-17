#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "queue.h"


queueADT newqueue() {
        queueADT queue;
        queue = (queueADT)malloc(sizeof(queueADT));
        queue->front = NULL;
        queue->back = NULL;
        queue->sz = 0;
        return queue;
}

cell* newcell(int n) {
        cell *c = (cell*)malloc(sizeof(*c));
        c->next = NULL;
        c->elem = n;
        return c;
}

int size(queueADT this) {
        return this->sz;
}

bool isempty(queueADT this){
    return this->sz == 0;   
}


void push(queueADT this, int n) {
        cell* c = newcell(n);
        if(isempty(this)) this->front = c;
        else {
                this->front->next = c;
                this->front = c;
        }
        this->sz++;
}

int front(queueADT this) {
        if(isempty(this)) exit(1);
        return this->front->elem;
}

void pop(queueADT this) {
        if(isempty(this)) exit(1);
        this->back = this->back->next;
        this->sz--;
}
        
