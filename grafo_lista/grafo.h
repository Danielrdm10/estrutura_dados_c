#ifndef GRAFO_MATRIZ
#define GRAFO_MATRIZ
#include "../linkedlist/linked.h"

typedef struct{
   No **L;
   int n;
   } Grafo;

Grafo* criar_grafo(int n);

void destruir_grafo(Grafo *p);

void inserir_aresta(Grafo *p, int u, int v);

void remover_aresta(Grafo *p, int u, int v);

int tem_aresta(Grafo *p, int u, int v);

void imprimir_aresta(Grafo *p);

#endif
