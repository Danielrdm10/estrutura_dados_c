#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin_busca.h"



No* criar_arvore(){
    return NULL;
}


void destruir_arvore(No **p){
    if (*p == NULL) return;
    destruir_arvore(&((*p)->esq));
    destruir_arvore(&((*p)->dir));
    free(*p);
    *p=NULL;
}


void imprimir_arvore(No *p, int h){
   int i;
   if (p != NULL){
       imprimir_arvore(p->dir, h+1);
       for (i = 0; i < h; i++)
	   printf("-");
       printf(" %d\n", p->chave);
      imprimir_arvore(p->esq, h+1); 
   }
}

void in_order(No *p){
    if (p != NULL){
        in_order(p->esq);
        printf("%d", p->chave);
        in_order(p->dir);
    }
}


No* buscar(No *p, int chave){
    if (p == NULL || chave==p->chave ) return p;
    if (chave < p->chave) return buscar(p->esq, chave);
    else return buscar(p->dir, chave);
}

No *inserir(No *p, int chave){
    No *novo;
    if (p==NULL){
        novo =(No*) malloc(sizeof(No));
	novo->esq = novo->dir = NULL;
	novo->chave = chave;
	return novo;
    }
    if (chave < p->chave)
        p->esq = inserir(p->esq, chave);
    else
	p->dir = inserir(p->dir, chave);
    return p;
}

/*

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


*/



