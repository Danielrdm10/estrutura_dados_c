#include <stdio.h>
#include "ListaCircular.h"


Lista *li;
int main(){

    li = criar_lista();
    struct aluno al = {123, "daniel",10,10,10};
    add_ini(li, al);
    printf("tamanho da lista e: %d\n", tamanho(li));
}