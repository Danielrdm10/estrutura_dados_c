#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    int n, m, i, u, v;
    scanf("%d %d", &n, &m);
    Grafo *G = criar_grafo(n);
    for (i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        inserir_aresta(G, u, v);
    }
    imprimir_aresta(G);
    return 0;
}


