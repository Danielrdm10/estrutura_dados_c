#include "pilha.h"
#include <stdlib.h>

Pilha* pilha_criar(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->L = criar_lista();
    return p;   
}

void pilha_destruir(Pilha **p){
    destruir_lista(&((*p)->L));
    free(*p);
    *p = NULL;
}

void pilha_adicionar(Pilha **p, int x){
    adicionar_inicio((*p)->L,x);
}

int pilha_topo(Pilha *p){
    return acessar_primeiro(p->L);
}

void pilha_remover(Pilha **p){
    remover_inicio((*p)->L);
}

int pilha_tamanho(Pilha *p){
    return tamanho(p->L);
}


