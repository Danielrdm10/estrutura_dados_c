#include "ListaCircular.h"
#include <stdlib.h>

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox;
} Elem;

Lista* criar_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li==NULL){
        return 0;
    }else{
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;
    int tam=0;
    Elem *no = *li;
    do{
        tam++;
    }while(no != (*li));

    return tam;
}

int add_ini(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL) return 0;
    
    no->dados = al;

    if((*li)==NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        };
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }

    return 1;
};

int add_fin(Lista* li, struct aluno al){
    if(li==NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL) return 0;

    no->dados = al;
    if((*li)==NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != *li){
            aux = aux->prox;
        }

        aux->prox = no;
        no->prox = *li;
    }

    return 1;
}

int remove_ini(Lista* li){
    if((*li)==NULL) return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no); 

}