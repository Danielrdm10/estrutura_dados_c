#ifndef FILA_H
#define FILA_H

#include "../lista_circular/circular.h"

//dados
typedef struct{
    int tam;
    No *L;
} Fila;



Fila* fila_criar();

void fila_destruir(Fila **F);

void fila_adicionar(Fila **F, int x);

int fila_topo(Fila *F);

void fila_remover(Fila **F);

int fila_tamanho(Fila *F);

#endif

