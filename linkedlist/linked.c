#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

No* criar_lista(){
    return NULL;
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
    No *aux = p;
    while (aux != NULL){
        printf("%d, ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void imprimir_recursivo(No *p){
    if (p != NULL){
        printf("%d, ", p->dado);
        imprimir_recursivo(p->prox);
    }
    else printf("NULL\n");
}

void adicionar_inicio(No **p, int x){

    No *aux;
    aux = (No*) malloc(sizeof(No));
    if (aux == NULL) exit(EXIT_FAILURE);
    
    aux->dado = x;
    aux->prox = *p;
    *p = aux;

    //int *add = (int*) malloc(sizeof(int));
    //*add = x;
    //*L->dado = *add;
}

void adicionar_final(No **p, int x){
    
    No *add = (No*) malloc(sizeof(No));
    add->dado = x;
    add->prox = NULL;
    if (*p == NULL) *p = add;
    else{
        No *aux = *p;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = add;
    }

}

int busca_valor(No *p, int x){
    while(p != NULL){
        if (p->dado == x) return 1;
        p = p->prox;
    }
    return 0;
}

void remover_inicio(No **p){
    No* q = *p;
    if (q == NULL) return;
    *p = q->prox;
    free(q);
}

void remover_final(No **p){
    No* q = *p;
    if(q == NULL) return;
    if(q->prox == NULL){
        *p ==NULL;
        free(q);
        return;
    }

    while (q->prox->prox != NULL){
        q = q->prox;
    }
    free(q->prox);
    q->prox = NULL;

}

void remover_valor(No **p, int x){

    No *q = *p;
    if (q==NULL) return;
    if (q->dado==x){
        *p = q->prox;
        free(q);
        return;
    }

    while (q->prox != NULL){
        if(q->prox->dado==x) break;
        q = q->prox;
    }

    if (q->prox==NULL) return;
    No *tmp = q->prox;
    q->prox = tmp->prox;
    free(tmp);

}
