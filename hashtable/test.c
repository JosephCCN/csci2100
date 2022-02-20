#include<stdio.h>
#include"hashtable.h"

void print(int a, char* b) {
        printf("%d %s\n", a, b);
}

int main(){
        HashTbADT h = newHashTable();
       insert(h, "hi", 1);
       insert(h, "kl", 2);
       forAllElement(print, h);
}
