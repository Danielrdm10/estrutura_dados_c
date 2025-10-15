#include <stdio.h>
#include "arvore_bin_busca.h"

int main(){
    int i, v[10] = {8,3,1,7,13,10,14,12,4,5};
    No *T = criar_arvore();
    for (i = 0; i < 10; i++) T = inserir(T, v[i]);
    imprimir_arvore(T, 0);
    int chave = 0;
    while(chave!=-1){
        printf("> "); scanf("%d", &chave);
	if(buscar(T, chave) != NULL){
	    printf("REMOVIDO\n");
	    remover(&T, chave);
	    imprimir_arvore(T, 0);
	}
	else printf("NAO\n");
    }

    destruir_arvore(&T);

return 0;

}
