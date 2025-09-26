#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

vetor* criar_vetor(int tam){
    vetor *v;
    v = (vetor*) malloc(sizeof(vetor));
    v->dados = (int*) malloc(tam * sizeof(int));
    v->n = 0;
    return v;
}

void destruir_vetor(vetor *v){
    free(v->dados);
    free(v);
}

int acessar(vetor *v, int i){
    return v->dados[i];
}

int tamanho(vetor *v){
    return v->n;
}

void adicionar_elemento(vetor *v, int x){
    /*v->dados[v->n] = x;
    v->n++; ******adiciona sem ordem*/
    int i;
    for(i=v->n; i >= 0 && v->dados[i] > x; i--){
        v->dados[i+1] = v->dados[i];
    }
    v->dados[i+i] = x;
    v->n++;
}

void remover_elemento(vetor *v, int i){
    /*v->dados[i] = v->dados[v->n-1];
    v->n--;  ******* simples*/
    for(; i < v->n; i++){
        v->dados[i] = v->dados[i+1];
    }
    (v->n)--;

}

int busca_binaria(int *dados, int l, int r, int x){
    int m = (l+r)/2;
    if (l > r) return -1;
    if (dados[m] == x) return m;
    else if (dados[m] < x) return busca_binaria(dados, m + 1, r, x);
    else return busca_binaria(dados, l, m-1, x);
}

int busca(vetor *v, int x){
    /*int i;
    for(i=0; i < v->n; i++){
        if(v->dados[i] == x) return i;
    }
    return -1;*/

    return busca_binaria(v->dados, 0, v->n-1, x);
}