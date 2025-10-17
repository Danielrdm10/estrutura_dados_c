#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

PQ* pq_criar(int tam){
    PQ* p = (PQ*) malloc(tam * sizeof(PQ));
    p->dados = (t_item*) malloc(tam * sizeof(t_item));
    p->n = 0;
    p->tam = tam;
    return p;
}

void pq_destruir(PQ **p){
    free((*p)->dados);
    free(*p);
    *p == NULL;
    }


int pq_vazia(PQ *p){
    return p->n == 0;
    }

int pq_cheia(PQ *p){
    return p->n == p->tam;
    }

void pq_adicionar(PQ *p, t_item item){
    if(!pq_cheia(p))
       {p->dados[p->n] = item;
        p->n++;}
    }

t_item pq_extrai_maximo(PQ *p){
    int j, max = 0;
    for (j = 1; j < p->n; j++){
        if (p->dados[max].chave < p->dados[j].chave) max = j;
    swap(&(p->dados[max]), &(p->dados[p->n-1]));
    p->n--;
    return p->dados[p->n];
        }
    }

