#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

No* criar_no(int x, No *l, No *r){
    No *no = (No*) malloc(sizeof(No));
    no->dado = x;
    no->dir = r;
    no->esq = l;
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

No* procurar_no(No *raiz, int x){
    if (raiz == NULL || raiz->dado == x)
        return raiz;
    No *esq = procurar_no(raiz->esq, x);
    if (esq != NULL)
        return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(No *raiz){
    int h_esq, h_dir;
    if (raiz == NULL)
        return 0;
    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);
    return(h_esq > h_dir ? h_esq : h_dir) + 1;

}

//reparar que so muda o onde e feito o print do no

void pre_order(No *raiz){
    if (raiz != NULL){
        printf("%d", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
void pos_order(No *raiz){
    if (raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d", raiz->dado);
    }
}

void in_order(No *raiz){
    if (raiz != NULL){
        in_ordem(raiz->esq);
        printf("%d", raiz->dado);
        in_ordem(raiz->dir);
    }
}

//largura usa fila

void largura(No *raiz){
    p_fila f;
    f = criar_fila();
    enfileirar(f, raiz);
    while(!fila_vazia(f)){
        raiz = desenfileirar(f);
        if (raiz != NULL){
            enfileirar(f, raiz->esq);
            enfileirar(f, raiz->dir);
            printf("%d", raiz->dado);
        }
    }

    destruir_fila(f);
}






