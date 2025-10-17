#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)
#define PAI(i) ((i-1)/2)
#define swap(a, b) {t_item tmp = *a; *a = *b; *b = tmp;}

void sobe_no_heap(PQ *p, int x);
void desce_no_heap(PQ *p, int x);

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
    p->dados[p->n] = item;
    p->n++;
    sobe_no_heap(p, p->n-1);
    }


void sobe_no_heap(PQ *p, int pos){
    if (pos > 0 && p->dados[PAI(pos)].chave < p->dados[pos].chave){
        swap(&p->dados[pos], &p->dados[PAI(pos)]);
        sobe_no_heap(p, PAI(pos));
        }
}

void desce_no_heap(PQ *p, int pos){
    if (F_ESQ(pos) < p->n){
        int maior_filho = F_ESQ(pos);
        if (F_DIR(pos) < p->n && p->dados[F_ESQ(pos)].chave < p->dados[F_DIR(pos)].chave){
            maior_filho = F_DIR(pos);
            }
        if (p->dados[pos].chave < p->dados[maior_filho].chave){
            swap(&p->dados[pos], &p->dados[maior_filho]);
            desce_no_heap(p, maior_filho);
            }
        }
    }

t_item pq_extrai_maximo(PQ *p){
    t_item item = p->dados[0];
    swap(&p->dados[0], &p->dados[p->n-1]);
    p->n--;
    desce_no_heap(p, 0);
    return item;
}

