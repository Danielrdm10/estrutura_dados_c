#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li !=NULL){
        li->qtd = 0;
    return li;
    }
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho(Lista* li){
    if(li==NULL){
        return -1;
    }
    else{
        return li -> qtd;
    }
}

int vazia(Lista* li){
    return li->qtd == 0;
}

int cheia(Lista* li){
    return li->qtd == MAX;
}

int incluir_fim(Lista* li, struct aluno add){
    if(li==NULL){
        return 0;
    }
    if(cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = add;
    li->qtd++;
    return 1;
}

int incluir_inicio(Lista* li, struct aluno add){
    if(li==NULL){
        return 0;
    }
    if(cheia(li)){
        return 0;
    }

    for(int i=li->qtd-1; i >= 0; i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = add;
    li->qtd++;
    return 1;
}
