#include<stdio.h>
#include"list.h"


void printall(listADT a) {
        if(isempty(a)) return;
        printf("%d ", head(a));
        printall(tail(a));
}

listADT mergeLists(listADT a, listADT b) {
        printf("a: ");
        printall(a);
        printf("\nb: ");
        printall(b);
        printf("\n");
        if(isempty(a)) return b;
        if(isempty(b)) return a;
        if(head(a) < head(b)) return con(head(a), mergeLists(tail(a), b));
        else return con(head(b), mergeLists(a, tail(b)));
}

void splitlist(listADT list, listADT* odd, listADT* even) {
        if(isempty(list)) return;
        splitlist(tail(list), odd, even);
        if(size(*odd) == size(*even)) *odd = con(head(list), *odd);
        else *even = con(head(list), *even);
}

int main(){
        listADT a = emptylist();
        listADT b = emptylist();
        listADT c = emptylist();
        for(int i=0;i<10;i++) a = con(i ,a);
        printall(a);
        printf("\n");
        splitlist(a, &b ,&c);
        printall(b);
        printf("\n");
        printall(c);
}
