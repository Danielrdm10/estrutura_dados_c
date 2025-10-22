#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criar_grafo(int n){
    int i;
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->n = n;
    g->L = (No**) malloc(n * sizeof(No*));
    for (i=0; i<n; i++){
        g->L[i] = criar_lista();
    }
    return g;
}

void destruir_grafo(Grafo *g){
    int i;
    for (i=0; i < g->n; i++){
        destruir_lista(&g->L[i]);
    }
    free(g->L);
    free(g);
}

int tem_aresta(Grafo *g, int u, int v){
    return busca_valor(g->L[u], v);
}

void imprimir_aresta(Grafo *g){
    int u;
    for (u=0; u < g->n; u++){
        printf("%d: ", u);
        imprimir_lista(g->L[u]);
    }
}

void inserir_aresta(Grafo *g, int u, int v){
    adicionar_final(&g->L[v], u);
    adicionar_final(&g->L[u], v);
}

void remover_aresta(Grafo *g, int u, int v){
    remover_valor(&g->L[u], v);
    remover_valor(&g->L[v], u);

}
