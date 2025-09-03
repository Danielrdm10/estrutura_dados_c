#include <stdio.h>
#include "listadinamica.h"

Lista *lista;

int main(){

    lista = cria_lista();

    struct aluno eu = {123456,"Daniel",10,9,8};
    struct aluno ele = {654987,"fulano",10,9,8};

    add_ini(lista, eu);   
    add_fin(lista, ele);  

    //rem_fim(lista);  
 
    int tam = tamanho(lista);

    printf("tamanho: %d\n", tam);
    printf("esta vazia? %d\n", vazia(lista));
    
    char nome[30];
    consulta(lista, 654987, nome);
    printf("o nome é: %s\n", nome);
}

