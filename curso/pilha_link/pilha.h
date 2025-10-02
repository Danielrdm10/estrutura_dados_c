#ifndef PILHA_L_H
#define PILHA_L_H

#include "../lista_circular/circular.h" //utiliza o padrao da fila circular linked

//dados
typedef struct{
    No *L;
} Pilha;

#define MAX 100


//funcoes
Pilha* pilha_criar();

void pilha_destruir(Pilha **F);

void pilha_adicionar(Pilha **F, int x);

int pilha_topo(Pilha *F);

void pilha_remover(Pilha **F);

int pilha_tamanho(Pilha *F);

#endif

