#include "listadinamica.h"
#include <stdlib.h>
#include <string.h>

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

int add_ini(Lista* li, struct aluno al){
    if(li==NULL) return 0;
    
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no==NULL) return 0;

    no->dados = al;
    no->prox = (*li);
    *li = no;
}

int add_fin(Lista* li, struct aluno al){
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

int rem_ini(Lista* li){
    if(li==NULL || *li==NULL) return 0;
    
    Elem *no = *li;
    *li = no->prox;
    free(no);

}

int rem_fim(Lista* li){
    if(li==NULL || *li==NULL) return 0;
    
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    
    if(no == (*li)){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;

}

int remover(Lista* li, int mat){
    if(li==NULL || *li==NULL) return 0;

    Elem *ant, *no = *li;

    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }

    if(no==NULL) return 0; //nao encontrado

    if(no==*li){
        *li == no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta(Lista* li, int mat, char nome[30]){
    if(li==NULL || *li==NULL) return 0;

    Elem *no = *li;

    while(no!=NULL && no->dados.matricula != mat){
        no = no->prox;
    }

    if(no==NULL){
        return 0;
    }else{
        strcpy(nome, no->dados.nome);
        return 1;
    }
}