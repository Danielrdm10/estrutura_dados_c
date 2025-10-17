#include <stdio.h>
#include "heap.h"

int main(){
    int n, i;
    scanf("%d", &n);
    PQ *Fila = pq_criar(n);
    for (i=0; i < n; i++){
        t_item item;
        scanf("%d %s", &item.chave, item.nome);
        pq_adicionar(Fila, item);
        }

    printf("Fila: \n");
    while(!pq_vazia(Fila)){
        t_item item = pq_extrai_maximo(Fila);
        printf("%d %s\n", item.chave, item.nome);
    }
    pq_destruir(&Fila);
return 0;
}
