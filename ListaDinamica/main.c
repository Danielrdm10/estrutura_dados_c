#include <stdio.h>
#include "listadinamica.h"


Lista *li;

int main(){

    li = cria_lista();
    int tam = tamanho(li);
    printf("tamanho: %d\n", tam);
    printf("esta vazia? %d\n", vazia(li));
    
}