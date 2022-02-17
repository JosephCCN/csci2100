#include<stdio.h>
#include"list.h"

int main(){
        listADT t = emptylist();
        t = con(1, t);
        printf("%d", size(t));
}
