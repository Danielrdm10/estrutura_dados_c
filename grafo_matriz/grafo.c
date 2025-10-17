#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *criar_grafo(int n){
    int i, j;
    Grafo *p = (Grafo*) malloc(sizeof(Grafo));
    p->n = n;
    p->M = (int**) malloc(n * sizeof(int*));
    for (i=0; i<n; i++){
        p->M[i] = (int*) malloc(n * sizeof(int));
    }
    for (i=0; i<n; i++){
        for(j=0; j<n; j++){
            p->M[i][j] = 0;
        }
    }
return p;
}

void destruir_grafo(Grafo *p){
    int i;
    for (i=0; i< p->n; i++)
        free(p->M[i]);
    free(p->M);
    free(p);
}

void inserir_aresta(Grafo *p, int u, int v){
    p->M[u][v] = 1;
    p->M[v][u] = 1;
}

void remover_aresta(Grafo *p, int u, int v){
    p->M[u][v] = 0;
    p->M[v][u] = 0;
}

int tem_aresta(Grafo *p, int u, int v){
    return p->M[u][v];
}

void imprimir_aresta(Grafo *p){
    int u, v;
    for (u=0; u < p->n; u++)
        for (v=u+1; v < p->n; v++)
            if (tem_aresta(p, u, v))
                printf("{%d,%d}\n",u,v);
}


