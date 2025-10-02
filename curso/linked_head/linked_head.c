#include <stdlib.h>
#include <stdio.h>
#include "linked_head.h"

No* criar_lista(){
    No *q = (No*) malloc(sizeof(No));
    q->dado = 0;
    q->prox = NULL;
}

void destruir_iterativo(No **p){
    No *q;
    while(*p != NULL){
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}

void destruir_recursivo(No *p){
    if (p != NULL){
        destruir_recursivo(p->prox);
        free(p);
    }
}

void destruir_lista(No **p){
    destruir_iterativo(p);
    //destruir_recursivo(*p); *p = NULL; **precisa tornar nulo, diferente da iteradita, onde o ultimo elemento ja atribuiu a null
}

void imprimir_lista(No *p){
    No *q;
    for (q = p->prox; q != NULL; q = q->prox) printf("%d ->", q->dado);
    printf("NULL\n");
}

void imprimir_recursivo(No *p){
    if (p != NULL){
        printf("%d, ", p->dado);
        imprimir_recursivo(p->prox);
    }
    else printf("NULL\n");
}

void adicionar_inicio(No *p, int x){
    No *add = (No*) malloc(sizeof(No));
    add->dado = x;
    add->prox = p->prox;
    p->prox = add;
    p->dado++; 

}

void adicionar_final(No *p, int x){
    
    No *add = (No*) malloc(sizeof(No));
    add->dado = x;
    add->prox = NULL;
    No *aux = p;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = add;
    p->dado++;    

}

int busca_valor(No *p, int x){
    p = p->prox;
    while(p != NULL){
        if (p->dado == x) return 1;
        p = p->prox;
    }
    return 0;
}

void remover_inicio(No *p){
    No* q = p->prox;
    if (q == NULL) return;
    p->prox = q->prox;
    free(q);
    p->dado--;
}

void remover_final(No *p){
    No* q = p;
    if(q->prox != NULL){
        while (q->prox->prox != NULL) q = q->prox;
        No *aux = q->prox;
	q->prox = NULL;
	free(aux);
    }
    p->dado--;
}

void remover_valor(No *p, int x){

    No *q = p;
    while (q->prox != NULL){
        if(q->prox->dado==x) break;
        q = q->prox;
    }

    if (q->prox==NULL) return;
    No *tmp = q->prox;
    q->prox = tmp->prox;
    free(tmp);
    p->dado--;

}

int tamanho(No *p){
    return p->dado;
}


