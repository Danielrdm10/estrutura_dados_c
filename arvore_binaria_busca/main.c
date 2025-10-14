#include <stdio.h>
#include "arvore_bin_busca.h"

int main(){
    int i, v[10] = {8,3,1,7,13,10,14,12,4,5};
    No *T = criar_arvore();
    for (i = 0; i < 10; i++)
        T = inserir(T, v[i]);
    imprimir_arvore(T,0);





    destruir_arvore(&T);

return 0;

}
