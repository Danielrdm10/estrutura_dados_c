#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criar_grafo(int n){
    int i;
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->n = n;
    g->L = (No**) malloc(n * sizeof(No*));
    for (i=0; i<n; i++){
        g->L[i] = criar_vetor();
    }
    return g;
}

void destruir_grafo(Grafo *g){
    int i;
    for (i=0; i < g->n; i++){
        destruir_vetor(g->L[i]);
    }
    free(g->L);
    free(g);
}

int tem_aresta(Grafo *g, int u, int v){
    return buscar(g->L[u], v);
}

void imprimir_arestas(Grafo *g){
    int u;
    for (u=0; u < g->n; u++){
        printf("%d: ", u);
        imprimir_vetor(g->L[u]);
    }
}

void inserir_aresta(Grafo *g, int u, int u){
    g->L[v] = inserir_elemento(g->L[v], u);
    g->L[u] = inserir_elemento(g->L[u], v);
}

void remover_aresta(Grafo *g, int u, int v){
    g->L[u] = remover_elemento(g->L[u], v);
    g->L[v] = remover_elemento(g->L[v], u);

}
