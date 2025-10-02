#include <stdio.h>
#include "linked_head.h"

int main(){

    int i, num;
    No *L = criar_lista();
    scanf("%d", &num);
    for(i=1; i<=num; i++) adicionar_inicio(L,i);
    imprimir_lista(L);
    while(tamanh(L)>0){
        scanf("%d", &i); remover_valor(L, i);
        imprimir_lista(L);
    }
    destruir_lista(&L);
return 0;

}
