#include "fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Elem;

Fila* cria_fila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila!=NULL){
        fila->final = NULL;
        fila->inicio = NULL;
};
    return fila;
}


int enqueue(Fila* fi, struct aluno al){
    Elem* el = (Elem*) malloc(sizeof(Elem));
    el == NULL;
    
    el->dados = al;
    el->prox = NULL;

    if(fi->inicio == NULL){
        fi->inicio = el;
        fi->final = el;
    }else{
        fi->final->prox = el;
        fi->final = el;
    }    
    printf("nome incluido no inicio da fila: %s\n", el->dados.nome);
};


int dequeue(Fila* fi){
    if(!fi || !fi->inicio) return 0;
    Elem* el = fi->inicio;
    fi->inicio = fi->inicio->prox;
    char retorno[30];
    strcpy(retorno, el->dados.nome);
    free(el);
    printf("nome retirado do final da fila: %s\n", retorno);
    return 1;
}


int tamanho(Fila* fi){
    Elem *aux = fi->inicio;
    int tam = 0;
    while(aux!=NULL){
        aux = aux->prox;
        ++tam;
    }
    return tam;
}

void show(Fila* fi){
    printf("ELEMENTOS DA FILA\n");
    Elem* el = fi->inicio;
    int tam = tamanho(fi);
    for(int i=0; i<tam; i++){
        printf("%d lugar: %s\n", i+1, el->dados.nome);
        el = el->prox;
    };
}