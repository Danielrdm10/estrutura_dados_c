#include "listadinamica.h"
#include <stdlib.h>

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li == NULL;
    }; 
    return li;
}

void libera(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
    }
}

int tamanho(Lista* li){
    if(li == NULL) return 0;

    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int vazia(Lista* li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}

void add_ini(Lista* li, struct aluno al){
    if(li==NULL) return 0;
    
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL) return 0;

    no->dados = al;
    no->prox = (*li);
    *li = no;
}

void add_fin(Lista* li, struct aluno al){
    if(li==NULL) return 0;
    
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL) return 0;

    no->dados = al;
    no->prox = NULL;

    if((*li)==NULL){
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=no;

    }

}
