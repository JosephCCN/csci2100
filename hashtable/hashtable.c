#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hashtable.h"
#include<stdbool.h>
const int hashkey = 32;


int hash(char *key) {
        int code = 0;
        int n = strlen(key);
        for(int i=0;i<n;i++) {
                code *= hashkey + key[i];
                code %= 100;
        }
        return code;
}

node findlastnode(node cp) {
        while(cp->next != NULL) cp = cp->next;
        return cp;
}

node newnode(char *key, int val) {
        node cp = (node)malloc(sizeof(node));
        cp->next = NULL;
        cp->key = key;
        cp->value = val;
        return cp;
}

HashTbADT newHashTable(){
        HashTbADT this = (HashTbADT)malloc(sizeof(HashTbADT));
        for(int i=0;i<100;i++) {
                this->bucket[i] = (node)malloc(sizeof(node));
                this->bucket[i] = NULL;
        }
        return this;
}

void insert(HashTbADT this, char *key, int val) {
        int code = hash(key);
        if(this->bucket[code] == NULL) {
                this->bucket[code] = newnode(key, val);
                return;
        }
       node cp = findlastnode(this->bucket[code]);
       cp->next = newnode(key, val);
}

int find(HashTbADT this, char* key) {
        int code = hash(key);
        node cp = this->bucket[code];
        while(cp != NULL && strcmp(cp->key, key) != 0) {
                cp = cp->next;
        }
        if(cp == NULL) return -1;
        if(strcmp(cp->key, key) == 0) return cp->value;
        else return -1;

}

void del(HashTbADT this, char* key) {
        int code = hash(key);
        node cp = this->bucket[code], prev = this->bucket[code];
        while(cp != NULL && strcmp(cp->key, key) != 0) {
                prev = cp;
                cp = cp->next;
        }
        if(cp != NULL) {
                if(cp == this->bucket[code]) this->bucket[code] = cp->next;
                else prev->next = cp->next;
                free(cp);
        }
        else exit(1);
}

void forAllElement(func f, HashTbADT this) {
        for(int i=0;i<100;i++) {
                node k = this->bucket[i];
                while(k != NULL) {
                        f(k->value, k->key);
                        k = k->next;
                }
        }
}
