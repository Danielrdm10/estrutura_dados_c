#include <stdio.h>
#include "ListaSequencial.h"

int main(){
    Lista *li;

    li = cria_lista();

    printf("Tamanho é %d\n",tamanho(li));
    printf("ta vazia: %d\n",vazia(li));
    printf("ta cheia: %d\n",cheia(li));

    struct aluno daniel = {50331272,"daniel",10,5,7};

    incluir_fim(li, daniel);

    struct aluno fulano = {0000,"aaaa",10,5,7};
    incluir_fim(li, fulano);

    printf("Tamanho é %d\n",tamanho(li));
    printf("ta vazia: %d\n",vazia(li));
    printf("ta cheia: %d\n",cheia(li));

    libera_lista(li);

}