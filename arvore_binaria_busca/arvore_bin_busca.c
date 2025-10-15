#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin_busca.h"

void remover_sucessor(No* p);


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
    if (p == NULL || chave==p->chave ) 
	return p;
    if (chave < p->chave) 
	return buscar(p->esq, chave);
    else 
	return buscar(p->dir, chave);
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

No* minimo(No *p){
    if (p == NULL || p->esq == NULL)
        return p;
    return minimo(p->esq);
}

No* minimo_interativo(No *p){
   while (p == NULL || p->esq == NULL){
       p = p->esq;
   }
   return p;
}

No* maximo(No *p){
    if (p == NULL || p->dir == NULL)
        return p;
    return minimo(p->dir);
}

No* maximo_interativo(No *p){
   while (p == NULL || p->dir == NULL){
       p = p->dir;
   }
   return p;
}

No* ancestral_a_direita(No *x){
    if (x == NULL) 
	return NULL;
    if (x->pai == NULL || x->pai->esq == x) 
	return x->pai;
    else
	return ancestral_a_direita(x->pai);
}

No* sucessor(No *x){
    if (x->dir != NULL)
        return minimo(x->dir);
    else
	return ancestral_a_direita(x);
    
}

No* remover_rec(No* p, int chave){
    if (p == NULL) return NULL;
    if (chave < p->chave)
	p->esq = remover_rec(p->esq, chave);
    else if (chave > p->chave)
	p->dir = remover_rec(p->dir, chave);
    else if (p->esq == NULL){
        No *q = p->dir; free(p);
	return q;
    }
    else if (p->dir == NULL){
        No *q = p->esq; free(p);
	return q;
    }
    else remover_sucessor(p);
    return p;
}

void remover(No **p, int chave){
    *p = remover_rec(*p, chave);
}

void remover_sucessor(No *p){
    No *min = p->dir;
    No *pai = p;
    while (min->esq != NULL){
        pai = min;
	min = min->esq;
    }
    if (pai->esq == min)
	pai->esq = min->dir;
    else
	pai->dir = min->dir;
    p->chave = min->chave; free(min);
}

