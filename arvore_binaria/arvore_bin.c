#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

No* criar_no(int x, No *l, No *r){
    No *no = (No*) malloc(sizeof(No));
    no->dado = x;
    no->dir = r;
    no->esq = j;
    return no;
}

void destruir_arvore(No **raiz){
    if (*raiz == NULL) return;
    destruir_arvore(&((*raiz)->esq));
    destruir_arvore(&((*raiz)->dir));
    free(*raiz);
    *raiz=NULL;

}


void printnode(int x, int h){
    int i;
    for (i=0; i < h; i++) printf("-");
    printf("%2d\n", x);
}

void print(No *p, int h){
    if (p == NULL) return;
    print(p->dir, h+1);
    printnode(p->dado, h);
    print(p->esq, h+1);
}

void imprimir_arvore(No *raiz){
    print(raiz,0);
}
