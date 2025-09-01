#include "mod.h"
#include <stdio.h>

int main(){
    float d;
    Ponto *p, *q;

    p = pto_cria(10,21);
    q = pto_cria(7,25);

    d = distancia(p,q);
    printf("A distancia entre os pontos é %f\n", d);

    float x, y;

    pto_acessa(p,&x,&y);
    printf("o valor de x é %.0f e y é %.0f\n", x, y);

    pto_atribui(p, 5,5);
    printf("o valor de x é %.0f e y é %.0f\n", p->x, p->y);


    pto_libera(q);
    pto_libera(p);
    

}