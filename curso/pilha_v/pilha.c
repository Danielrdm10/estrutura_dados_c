#include "pilha.h"
#include <stdlib.h>

Pilha* pilha_criar(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = malloc(MAX*sizeof(int));
    p->topo = 0;
    p->N = MAX;
    return p;
}

void pilha_destruir(Pilha **p){
    free((*p)->dados);
    free(*p);
    *p = NULL;
}

void pilha_adicionar(Pilha **p, int x){
    if ((*p)->topo >= MAX) return;
    (*p)->dados[(*p)->topo]= x;
    (*p)->topo++;

}

int pilha_topo(Pilha *p){
    return p->topo ? p->dados[p->topo-1] : -1;
}

void pilha_remover(Pilha **p){
    if ((*p)->topo == 0) return; 
    (*p)->topo--;
}

int pilha_tamanho(Pilha *p){
    return p->topo;
}


