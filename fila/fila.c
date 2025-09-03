#include "fila.h"
#include <stdlib.h>

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct elemento{
    struct aluno al;
    struct elemento *prox;
} Elem;

Fila* cria_fila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila!=NULL){
        fila->final = NULL;
        fila->inicio = NULL;
};
    return fila;
}