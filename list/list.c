#include<stdlib.h>
#include "list.h"

struct listCDT{
        int head;
        listADT tail;
};

int head(listADT this) {return this->head;}
listADT tail(listADT this) {return this->tail;}

listADT emptylist() {
        return ((listADT)NULL);
}

listADT con(int a, listADT this) {
    listADT t = (listADT)malloc(sizeof(*t));
    t->head = a;
    t->tail = this;
    return t;
}

int size(listADT this) {
        if(this == NULL) return 0;
        else return size(tail(this)) + 1;
}

int isempty(listADT this) {
        return this==NULL;
}
